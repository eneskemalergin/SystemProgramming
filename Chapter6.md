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

![]()
