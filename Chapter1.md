---
Class  : Systems Programming
Date   : 01/20/2016
Author : Enes Kemal Ergin
Subject: Chapter 1 - Introduction
---

# Introduction

Systems programming is the use of programs while developing them, by modifying small bits.

In this course we will use three main tools; __shell(terminal)__, __debugger__, and __text editor.__

## Shell

__Basic Commands:__

 - ls : list all the files in current directory
 - cd : change directory
 - pwd: print the working directory.

__Common System Programs:__

  - grep: Search files for specific text
  - less: Preview the file with using lesser memory space
  - more: Preview the file with using a little more memory space than less command,
  - sort: Sort files
  - awk : Tools to handle text files

## Text editor

I will use the command line text editor ```vim``` to write my codes. Here are some reference notes for ```vim```; [link](http://tnerual.eriogerg.free.fr/vimqrc.pdf)

> Also this is interactive tutorial to vim : [link](http://www.openvim.com)


## Debugger
  Debugger allows programmer to test the program one step at a time by executing line by line. There are a lot of debugger programs but in this class we will examine the GNU debugger, ```gdb```. We are assuming that we have a source file called ```sum.c```. In order to compile it we need to write ``` $ gcc sum.c```. This command will compile the file and store the binary version in ```a.out``` file. Then by simply executing ```a.out``` file you can see the output of the source code.

In order to run the program with debugger we need to add ```-g``` to compilation command.

```Shell
$ gcc -g sum.c
$ gdb ./a.out
(gdb) run
.... // Information...
....
....  
(gdb) quit
 ```

 For more information about GNU debugger, [GDB tutorial](http://www.unknownroad.com/rtfm/gdbtut/)
