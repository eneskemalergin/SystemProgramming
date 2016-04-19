---
Class  : Systems Programming
Date   : 04/19/2016
Author : Enes Kemal Ergin
Subject: Chapter 6 - Program Management
---

Program Management concerns the following: organization, building and distribution.

## Program building

After a program is written, it must be built into an executable so that it can be run. There are steps to transfer user written code to computer understandable code. In each step code transforms to an intermediate form; pre-processed, assembly code, object code, and libraries.

Understanding these intermediate forms and their transformations will give you ability to optimize your code.

### Object Code and Linking

```C
#include <stdio.h>
int OurSquareRoot(int n){
  if (n == 4)
    return(2);
  else{
    printf("I cannot compute the square root of %d\n", n);
    return(-1);
  }
}
```

Let's talk about the concept by going through this example.

![Figure 6.1](https://raw.githubusercontent.com/eneskemalergin/SystemProgramming/master/figures/figure.6.1.jpg)

It can be compiled into object code as follows:

```Bash
> ls
sqrt.c

> gcc -c sqrt.c
> ls
sqrt.c sqrt.o

```

- The ```-c``` flag tells gcc stop after the compile stage and not to proceed to linking.
- ```sqrt.o``` contains object code, which contains the machine code (instructions that can be run on the processor.)
- Object code cannot be executed directly, they need to be linked to become executable.

```C
// Let's name this main.c
#include <stdio.h>
int OurSquareRoot(int);
int main(int argc, char const * argv[]) {
  int x,s;

  printf("Enter any integer: ");
  scanf("%d", &x);

  s = OurSquareRoot(x);

  if (s != -1)
    printf("The square root of %d is %d\n", x,s);
  return 0;
}
```

Let's link them together in the command line:

```Bash
> gcc -c sqrt.c # Same as we did
> gcc -c main.c # Now we also compile main
> ls            # list file created
main.c main.o sqrt.c sqrt.o
> gcc sqrt.o main.o #
> ls
a.out main.c main.o sqrt.c sqrt.o

```

At the end ```a.out``` created by linking together the two object files. If you would try to compile and execute the ```sqrt.c``` directly it will throw an error since there was no main function in it. But using object files and linking them together we get rid of this error.

When compiling, unless otherwise instructed, gcc will automatically proceed to linking, and then remove any object code files it created.

Linking primarily serves to bring together object code files into an executable. However, it can also bring in object code from library files.

![Figure 6.2](https://raw.githubusercontent.com/eneskemalergin/SystemProgramming/master/figures/figure.6.2.jpg)

Library files contain object code for functions that are frequently used. In this way, the source code can be compiled once and stored in a permanent place, ready to link.

The flag ```-lc``` tells the gcc compiler to link to a library file named ```libc.a``` (C Standart Library).

Why the executable can be created with or without having to explicity link to the libc.a library file (with or without the -lc flag)? The reason is that this file is so commonly linked, most compilers are set up to assume that it is needed and so link to it by default.


### Compiling
The compile process transforms a source code file into an object code file.

![Figure 6.3](https://raw.githubusercontent.com/eneskemalergin/SystemProgramming/master/figures/figure.6.3.jpg)

- The first step is preprocessing. Preprocessing provides mechanisms to support text substitutions, also called macros or macro substitutions.

```C
#include <stdio.h>
#define PI 3.14
#define SQRT2 1.7
int main(int argc, char * argv[]){
  printf("PI = %lf\n",PI);
  printf("PI = %lf and the square root of 2 = %lf\n",PI,SQRT2);
  }
```
- The line ```#define PI 3.14``` is a preprocessor directive. It says to replace every occurrence of ```PI``` with 3.14.
- The flag ```-E``` stops the compilation process after preprocessing.

```Bash
> gcc -E pre1.c

int main(int argc, char *argv[])
{
printf("PI = %lf\n",3.14);
printf("PI = %lf and the square root of 2 = %lf\n",3.14,1.7);
}
```

- Preprocessing used in place of a variable, they prevent the accidental changing of the value during program execution.
- They also save storage space in that a macro takes up zero bytes of data memory.
- Preprocessing copies source code that is needed repeatedly, usually from an include file.

Let's make an example make it more clear:

```C
// Name this globals.h
/* global variables */
int x;
```

We will include ```globals.h``` in ```pre2.c```

```C
#include "globals.h"
int main(int argc, char * argv[])
{
x=2;
printf("x=%d\n",x);
}
```

Compiling it and stopping after preprocessing produces the following result:

```C
> gcc -E pre2.c

/* global variables */
int x;
int main(int argc, char * argv[])
{
x=2;
printf("x=%d\n",x);
}
```

As you can see the preprocessing adds the ```globals.h``` which we put in the include.

> By enclosing the filename in angle brackets (< >), the preprocessor is told to search system paths for the include file. By enclosing the filename in double quotes (" "), the preprocessor is told to search within the current directory for the include file.


<span style=\"color:red\">Any statement that begins with a pound symbol (#) is a preprocessor directive, not C code.</span>

Other common preprocessor directives are ```#if```, ```#else```, ```#endif```, ```#ifdef```, and ```#ifndef``` to allow for control of what string substitutions are performed.

```C
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1 /* debugging output */

main() {
  int x,y,s;
  y=1;
  s=0;
  for (x=0; x<10; x++){
    y=y<<1;
    s=s+y;
  #if DEBUG == 1
    printf("When x=%d, y=%d\n",x,y);
  #endif
    }
  printf("s=%d\n",s);
}
```

Assume that this code is stored in a file named ```pre3.c```. Changing the value of ```DEBUG``` to 0 will prevent the debugging ```printf()``` statement from executing.

---

The second step in the compilation process is the actual compiling, which converts the C source code into assembly code, and also be stopped after this point.

The ```-S``` flag tells the compiler to stop after compiling. The compiler saves the result in an assembly code file ```pre3.s```. An example content would look like this:

```
    .file   "pre3.c"
    .section .rodata
.LC0:
    .string "When x=%d, y=%d\n"
.LC1:
    .string "s=%d\n"
    .text
.globl main
    .type main, @function
main:
    pushl %ebp
    movl %esp, %ebp
    subl $24, %esp
    andl $-16, %esp
    movl $0, %eax
    addl $15, %eax
    addl $15, %eax
    shrl $4, %eax
    sall $4, %eax
    subl %eax, %esp
[...]

```

The assembly code is the set of instructions that will be executed on the processor. For example, ```movl``` and ```subl``` are processor-level instructions. The exact assembly listing produced by compiling will depend upon the particular processor for which the program is compiled.

---

The third and final step in the compilation process is called _assembling._ During this step, assembly code is translated into machine code to get it ready to run.

- The assembly instruction is a human-readable translation of those byte values.


### Makefiles

- A makefile is a tool that allows a programmer to organize the compile commands and intermediate files and to execute rebuilds with less manual typing.
- A makefile is a text file placed in the current working directory, usually the directory holding the source code to be compiled.
- A makefile has two main parts: dependencies and commands, (Format of dependency/command:)

```
file : dependency
[TAB] command
[TAB] command

[...]

```
A dependency describes a relationship between files, where if the file on the righthand side of the dependency is changed, then the file on the left-hand side needs rebuilding.

The command(s) to perform the rebuilding are listed after the dependency.

A makefile example:

```
sqrt : main.o sqrt.o
        gcc -o sqrt main.o sqrt.o
main.o : main.c
        gcc -c main.c
sqrt.o : sqrt.c
        gcc -c sqrt.c
```

- three dependency/command blocks
  - In the first, the executable file ```sqrt``` is defined as depending upon the two object code files ```main.o``` and ```sqrt.o```.
  - The second and third blocks give dependencies for the object code files, as well as commands to compile the source code files into the object code files.

Assuming that neither the object code files nor the executable file exists, then this makefile can be used to build the program as follows:

```Bash
> ls
main.c Makefile sqrt.c
> make
gcc -c main.c
gcc -c sqrt.c
gcc -o sqrt main.o sqrt.o
> ls
main.c main.o Makefile sqrt sqrt.c sqrt.o
>
```

The ```make``` program parses that file for dependencies and executes the commands for any dependency that needs updating in the current directory if Makefile exists.

> Notice that with the makefile, the only command that needs to be typed is “make”; all the others are executed automatically.


If ```make``` once executed, writing ```make``` again won't change anything or do anything in the command line. However, modifying something in the ```.c``` files you have to ```make``` again...

Makefiles can have other lines in them besides dependencies and commands;

- Comments can be written after the ```#``` character.
- Macros can be written to define string substitutions.

```
EXEC = sqrt
$(EXEC) : main.o sqrt.o
```

---

## Code Organization
