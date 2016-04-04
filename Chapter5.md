---
Class  : Systems Programming
Date   : 04/04/2016
Author : Enes Kemal Ergin
Subject: Chapter 5 - Input/Output
---

To make things more interesting we could use get some input from somewhere and get some output to somewhere. There are several ways to make this input/output (I/O) interaction happens, typically through a keyboard and display. __File I/O__ involves interaction between __program__ and __storage system__, while __device I/O__ involves interaction between __program__ and __piece of hardware.__

In this chapter we won't only deal with text input/output, which was ```printf()``` and ```scanf()``` most of the times, but we will see the I/O of data as raw bytes.

## Streams
I/O interaction occurs when a program receives bytes from a source (using keyboard, mouse, file, or sensor) or sends bytes to a destination (to to display, file, printer, and actuator).

Most modern operating systems use a concept, which any input or output transaction can be viewed as a _flow of bytes_ from a source to a destination, called __stream model__.

An I/O connection established using ```fopen()``` function. For example:

```C
FILE *fpt;
fpt=fopen("output.txt", "w");
fprintf(fpt, "This is a test.");
fclose(fpt);
```

When ```fopen()``` function is called, a stream connection is established, then ```fprintf()``` comes into play to pass those bytes(text in this case) into file with stream. At last ```fclose()``` is called and that stream connections is broken.


### Transporting Bytes on Stream
As you have guessed already there are some function that you can use to transport bytes on stream, such as ```fprintf()``` and ```fscanf()```.


```C
#include<stdio.h>
int main(){
  FILE * fpt;
  fpt = fopen("data.txt", "w");
  fprintf(fpt, "Fortytwo 42 bytes of data on the wall...");
  flose(fpt);
}
```

After executing the code above now we simply transported bytes to ```data.txt``` file, so now we will see the file created and available us to see it.

```C
#include<stdio.h>
int main(){
  FILE * fpt;
  char text[80];
  fpt = fopen("data.txt", "r");
  fscanf(fpt, "%s", text);
  printf( "%s\n", text);
  fclose(fpt);
}
```

The generic functions for transporting bytes on streams are ```fread()``` and ```fwrite()```.

```C
#include <stdio.h>
int main(){
  FILE * fpt;
  char text[80];
  fpt = fopen("data.txt", "r");
  fread(text, 1, 15, fpt);
  text[15]=0;
  printf("%s\n", text);
  fclose(fpt);

}

/* Output :
  Fortytwo 42 byt
*/
```

In the example above, we showed a usage of ```fread()``` function. Now let's see the parameters of ```fread()``` function:

- First parameter provides the address at which the received bytes are stored
- Second and third parameter gives the limitation of byte size.
- Last parameter in the example above is the file pointer to the stream on which bytes are being received.


The ```fwrite()``` function moves bytes from the program to a destination. Let's see an example:

```C
#include <stdio.h>
int main(){
  FILE * fpt;
  char text[80];
  sprintf(text,"Fortytwo 42 bytes of data on the wall...");
  fpt=fopen("data2.txt","w");
  fwrite(text,1,strlen(text),fpt);
  fclose(fpt);
}
```

After executing the example above, you will have another file called ```data2.txt```, which is identical to first file. ```fwrite()```  parameters are the same as ```fread()```

Another advantage of using ```fread()``` and ```fwrite()``` is that it allows the programmer a simple way to check when the end of a file has been reached. The return value of both functions is an indicator of the number of bytes actually moved along the stream.

```C
#include <stdio.h>
int main(){
  FILE * fpt;
  char text[80];
  int bytes_read;
  fpt=fopen("data.txt","r");
  bytes_read=fread(text,1,70,fpt);
  printf("%d\n",bytes_read);
  fclose(fpt);
}

// Output:
// 40
```

In the example above we say, ok ```fread()``` function use 70 cells, however we have 40 bytes of data in hand, when the data is ended ```fread()``` automatically terminates. The return value for the ```fread()``` function is the number of cells of data moved along the stream.


Even they are other functions to move bytes on streams like ```fgetc()```, ```fputc()```, ```gets()```, and ```puts()```, to simplify moving text data, to use ```fread()``` and ```fwrite()``` would be more precise and error free.

### System I/O Functions
There is another set of functions that can be used for I/O. These functions include ```open()```, ```close()```, ```read()```, and ```write()```.  So , what is the difference between f-versions of those functions?

- The non-f I/O functions are system calls. Depending on which operating system they are called from, they may behave differently.
- The f-versions of the I/O functions are standardized in the C library. A programmer can expect them to behave similarly regardless of the underlying system.

### Standard Streams
Every time a program is started, the O/S automatically creates three streams, which we name them "standard streams."

- The first stream is called the “standard in” stream and is abbreviated ```stdin```. _It connects the keyboard to the program._
- The second stream is called the “standard out” stream and is abbreviated ```stdout```. _It connects the program to the display._
- The third stream is called the “standard error” stream and is abbreviated ```stderr```. _It connects the program to a secondary display that is intended only for the display of errors._

> ```stderr ``` is often connected to the same terminal display as the stdout stream but can be connected to a different display.

---

## Buffers
