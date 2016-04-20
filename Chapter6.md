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


<p style=\"color:red\">Any statement that begins with a pound symbol (#) is a preprocessor directive, not C code.</p>

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

Code organization in other words, making code modular, readable, and understandable is very important and very time consuming.

- Writing well-organized code generally leads to a cleaner program design, which in turn generally leads to fewer flaws and bugs.
- It is much easier to find errors in well-organized code, particularly if a bug is uncovered long after the code was written and the author has forgotten much of the design.
- Promote code reuse and future program extension.

### functions
Using multiple functions is the most classic approach to making a program modular. Modularity is desirable for two reasons:

- It divides a coding problem into pieces (divide and conquer)
- It allows code pieces to be reused in future programming tasks.

Let's see a modular approach example code:

```C
#include <stdio.h>
#include <string.h>

int ReadData(FILE * fpt, char first[20][30], char last[20][30]){
  int total;
  total=0;

  while (1){
    if (fscanf(fpt,"%s %s",last[total],first[total]) != 2)
    break;
    total++;
  }

  return(total);
}

void CapFix(char word[30]){
  int i;
  if (word[0] >= ’a’ && word[0] <= ’z’)
    word[0]=word[0]-’a’+’A’;

  for (i=1; i<strlen(word); i++)
    if (word[i] >= ’A’ && word[i] <= ’Z’)
      word[i]=word[i]-’A’+’a’;
}
int main(int argc, char * argv[]){
  FILE * fpt;
  char first[20][30],last[20][30];
  int i,j,total;

  if (argc != 2){
    printf("Usage: capfix [filename]\n");
    exit(0);
  }

  if ((fpt=fopen(argv[1],"r")) == NULL){
    printf("Unable to open %s for reading\n",argv[1]);
    exit(0);
  }

  total=ReadData(fpt,first,last);

  for (i=0; i<total; i++)
    CapFix(first[i]);

  for (i=0; i<total; i++)
    CapFix(last[i]);

  for (i=0; i<total; i++)
    printf("%s %s\n",first[i],last[i]);
}
```  

Functions are a good tool for organizing code, but like any tool they can be used inappropriately.

Calling a function takes extra program execution time, both for copying values into and out of the function, and for jumping to and from the function code for execution.

Another mistake is to overuse functions. Just because some code can be encapsulated into a function doesn’t mean it should be encapsulated into a function. (__Debugging and modifying code that has been “over-functionalized” can be frustrating.__)


### Multiple Files
As the number of functions in a program increases, it is convenient to break them up into multiple files.

- It makes it easier to edit a file.
- It makes program building more efficient.

### Variable Scope
When breaking a program into multiple functions and files, scope is a tool that can help organize variable usage. The scope of a variable is defined in its declaration. A C variable declaration can have four parts:

1. Data type: ```int, float, char, double```. (describe how many bytes of storage are used by the variable)
2. Modifiers: ```signed, unsigned, short, long```. (modify how many bytes are used and how the bits may be used.)
3. Qualifiers: ```const, volatile```. (provide information to the compiler as to how the variable will be used so that it may optimize appropriately)
4. Storage class: ```auto, static, extern```. (affect the scope of the variable, that is, the visibility of the variable throughout the program)

In this part of the chapter out main concern possible storage class and how it can be used. (4th part)

An ```auto``` variable is visible only within its code block, and is usually omitted since it's default storage class.

```C
int Function1(float e) {
  int x;
  auto int y;
  [...]
}
```

In the example above, all variables have same storage class ```auto```, either it's written or not.

---

A ```static``` variable has a larger variable scope. The static keyword can be used in two contexts, either within a single function or within an entire file.

- In the first case, the static storage class makes the value of the variable persistent through consecutive function calls:

```C
#include <stdio.h>

int summer(int x) {
  static int sum=0;
  sum=sum+x;
  return(sum);
}
int main(){
  int i,j;
  for (i=0; i<5; i++){
    j=summer(i);
    printf("%d\n",j);
  }
}
```

The variable ```sum``` has function static scope. If this code is stored in a file named ```function-static.c```, then compiling it and executing it produces the following output:

```Bash
> gcc -o function-static function-static.c
> function-static
0
1
3
6
10
>
```

Each time the function ```summer()``` is called, the value of the variable ```sum``` is retained.

- The ```static``` storage class provides a second scope that is similarly persistent but has a larger scope.

```C
#include <stdio.h>
static int sq=0;
int summer(int x){
  static int sum=0;
  sum=sum+x;
  sq=sq-1;
  return(sum);
}

int main() {
  int i,j;
  for (i=0; i<5; i++){
    sq=sq+(i*i);
    j=summer(i);
    printf("%d %d\n",j,sq);
  }
}
```
The variable ```sq``` has file static scope. If this code is stored in a file named ```filestatic.c```, then compiling it and executing it produces the following output:

```Bash
> gcc -o file-static file-static.c
> file-static
0 -1
1 -1
3 2
6 10
10 25
>
```

The value of ```sq``` is retained throughout all the function calls for this program.

---

An ```extern``` variable is a global variable being shared between multiple files. In order to use the extern keyword, a variable must first be declared with file scope:

```C
  // ext1.c
#include <stdio.h>
int x;
int main(int argc, char * argv[]){
  x=1;
  printf("main: %d\n",x);
  function();
  printf("main: %d\n",x);
}
```

```C
  // ext2.c
#include <stdio.h>
extern int x;
void function(){
  printf("function: %d\n",x);
  x=7;
  printf("function: %d\n",x);
}
```

The variable ```x``` is declared using the extern storage class, so that it has global scope.Compiling and executing this code produces the following output:

```Bash
> gcc -o ext ext1.c ext2.c
> ext
main: 1
function: 1
function: 7
main: 7
>
```

- Note that the value of ```x``` is maintained through all functions in both files.
- To create a variable with global scope, it must be declared in one file, and then referenced as an extern in all other files that want to access it.


### Comments, Indentation, and Variable Names

- Readability is the key...
- __Comments__  are annotations made by the programmer
- __Indentation__ is proper spacing to make things look organized.
- __Variable names__ should be chosen to help describe what the variable is.

---


## Program Distribution

- If the target distribution is systems that are exactly the same as the one on which the program is written, than the executable can be distributed.

- If the target computers run different operating systems or have different hardware, then either the source code must be compiled for all the desired platforms prior to distribution, or the source code itself needs to be distributed so that it can be compiled on the target systems.

### Archives

- An archiving tool groups together a set of files into a single file called an _archive file_, which contains the contents of all the individual files plus some metadata.

> The metadata usually details the sizes of the files, the last modified dates and times of the files, each file’s path or subdirectory, and possibly additional information.

The ```tar``` program is used more generically for almost any type of file:

```Bash
> ls
main.c Makefile sqrt.c

> tar cf dist.tar *

> ls
dist.tar main.c Makefile sqrt.c

> tar tf dist.tar # Check inside the .tar
main.c
Makefile
sqrt.c

>
```

the ```tar``` was used to create an archive file named ```dist.tar``` containing all files in the current directory.

The ```tar``` program does not provide compression. Instead, it relies upon the ```gzip``` compression tool for post-archiving compression and decompression. For example:

```Bash
> ls -l
-rw-r--r-- 1 ahoover fusion 10240 Oct 15 2008 dist.tar
-rw-r--r-- 1 ahoover fusion 221 Oct 15 2008 main.c
-rw-r--r-- 1 ahoover fusion 125 Oct 15 2008 Makefile
-rw-r--r-- 1 ahoover fusion 171 Oct 15 2008 sqrt.c

> gzip dist.tar
> ls -l dist.tar.gz
-rw-r--r-- 1 ahoover fusion 485 Oct 15 2008 dist.tar.gz
>
```

- Note that the archive file was originally larger than even the sum of the contents of the individual files inside it.

### Packages
A package management system is a more advanced program distribution tool. A package file is similar to an archive file, but it contains additional information:

- may describe how to compile or execute files extracted from the package file
- may describe how to install or organize files on a target system
- where the exact destination of each file depends upon how the target system is configured


The packages stored there sometimes contain executables built for specific target systems. Using packages in this manner is not very different from using more traditional archive files.

- Advantage: installation of such a package is quick;
- Disadvantage: the build contained within the package must exactly match the specifications of the target system

> End of Chapter...
