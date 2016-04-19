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
A buffer is a __temporary storage__ between _the sender_ and _the receiver_ of bytes on a stream.

A buffer is useful in a variety of situations. For example, what if the sender puts bytes into the stream faster than the receiver can handle? Or what if program is in the middle of a calculation and is not prepared to receive any bytes? The buffer can store up the bytes until the program is able to handle them, receiving them either at the reduced rate or when it is ready for them. There are three types of buffering, which differentiated by how they flushed the temporary storage they have used:

- Block Buffering:

  - In a block buffer, a fixed-size chunk of memory is filled before being passed on to the receiver.
  - Used for large data transfers, such as file I/O.


- Line Buffering:

  - In a line buffer, any bytes inside the buffer are sent to the receiver once a newline character (byte value of 13) is received. The newline character is also sent to the receiver.
  - Line buffering is typically used for text-based I/O, such as when interacting with a user.

- Unbuffered:

In a unbuffered each byte is sent to the receiver as soon as it is placed in the buffer. The buffer operates as though it is transparent.


---

## Pipes
- The process of connecting and reconnecting streams is referred to as piping, or pipelining.
- As we said before, the O/S automatically creates three streams for every running program.

In the following snippet, we prompt the user for integers, reporting the sum as each new number is entered. It exits when a value of zero is entered. If the code is stored in a file called ```summer.c```

```C
#include<stdio.h>
main(){
int x,s;
s=0;
while (1){
  printf("#? ");
  scanf("%d",&x);
  if (x == 0)
    break;
  s=s+x;
  printf(" sum=%d\n",s);
  }
}

/* Output in terminal
$ gcc -o summer summer.c
$ summer
#? 4
  sum=4
#? 1
  sum=5
#? 7
  sum=12
#? 0
*/
```

Now let's say we created an input file contains the following;

```
4
1
7
0
```

then we will feed this file into the program using pipelining operators...

The ```<``` symbol allows the user to redirect the stdin stream to a file instead of the keyboard. We will use the same snippet before but different approach in terminal:

```Bash
$ summer < input1.txt # As you can see here we are feeding input1.txt into our program...
#? sum=4
#? sum=5
#? sum=12
#?
```

The > symbol allows the user to redirect the stdout stream to a file instead of to the display. This symbol allow us to store the output from following program to specified output file:

```Bash
$ summer > output1.txt
4
1
7
0

# If we want to check what's inside the output1.txt
> less output1.txt
#? sum=4
#? sum=5
#? sum=12
#?

```

### Pipeline Chaining
Multiple piping redirections can be done simultaneously.

```Bash
$ summer < input1.txt | bingo > output2.txt
$ more output2.txt
Bingo!

```

Pipelining the output of one program to the input of another program can be done repeatedly. This allows us to write programs that perform single, simple operations, and to link them together into complex chains in order to accomplish tasks.

This pipelining is very useful when you work with linux base libraries, such as ```sed```, ```grep```, ```cut```, etc.


### Program Testing
Pipelining can be used for testing programs. Defining input files and storing into output files, as we discussed before, will help you a lot. Imagine that you have to test your program dozens of times with pre-defined input using pipelining will save you a great deal of time. This type of file considered to be a test pattern/input.

---

## Files

- A file is a one-dimensional array of bytes, regardless of what sort of data stored inside.
- For data like image, database, movie, we store multi-dimensional inside the one-dimensional array, as previously discussed in chapter 3
- Only difference when it comes to data types, is which bit model was used to group and encode the bytes.

One of the main job of the OS is to manage file storage.

### File Pointer
A marker used to keep track of the location for reading or writing on a stream. When we open the file file pointer points to the first byte and automatically advanced to next one when byte read.

Let's see the motion of the file pointer on ```data.txt``` file contains ```abcdef```:

```C
#include<stdio.h>
int main(){
  char byte;
  FILE *fpt;   // f*
  fpt = fopen("data.txt", "r");
  fread(&byte, 1, 1, fpt);
  fclose(fpt);
}
```

When the file is first opened, the file pointer has a value of 0, indicating that it points to the first byte in the file. After first byte is read, the file pointer is advanced to point to the second byte. We can continue to our exploration on memory map:

Byte  | Value
----- | ----
0     | 'a' (97)
1     | 'b' (98)
2     | 'c' (99)
3     | 'd' (100)
4     | 'e' (101)
5     | 'f' (102)


- The value of the file pointer, and hence its location, can be manipulated by ```fseek()``` function. ```fseek()``` assigns a new value without reading or writing any data on the stream.
- The current value of the file pointer can be obtained using the ```ftell()``` function.

```C
#include <stdio.h>
int main(int argc,char *argv[]){
  FILE *fpt;
  char byte;
  long int where,move;
  if (argc != 2)
    {
    printf("Usage: fileseek filename\n");
    exit(0);
    }
  if ((fpt=fopen(argv[1],"r")) == NULL)
    {
    printf("Unable to open %s for reading\n",argv[1]);
    exit(0);
    }
  while (1)
    {
    where=ftell(fpt); /* where is file pointer? */
    fread(&byte,1,1,fpt); /* moves fpt ahead one byte */
    fseek(fpt,-1,SEEK_CUR); /* back up one byte */
    printf("Byte %d: %d (%c)\n",where,byte,byte);
    printf("Enter #bytes (+ or -) to move, or 0 to quit: ");
    scanf("%d",&move);
    if (move == 0)
      break;
    fseek(fpt,move,SEEK_CUR); /* move to desired byte * /
    }
  fclose(fpt);
  }
```

This program opens a file and allows the user to move the file pointer. It reads 1 byte and displays the byte value using both the ASCII and two's complement bit models. as well as the file pointer value for that value. This repeated until the user enters 0 to quit.


### File Attributes

When you use ```ls -l ``` command on linux shell, you will see a lot of information about the files in the current directory. Something like this:

```Bash
> ls -l
-rw-r--r-- ahoover fusion 808 Jul 5 16:58 fileseek.c
-rwxr-xr-x ahoover fusion 14196 May 28 16:18 ls1
-rw-r--r-- ahoover fusion 468 May 28 20:21 ls1.c
-rw-r--r-- ahoover fusion 803 Jul 5 16:58 statfile1.c
-rw------- ahoover fusion 758 Jul 5 16:58 statfile2.c
-rw-r--r-- ahoover fusion 7 Jul 5 16:58 testme.txt
```

In this list, each row provides information about a file.

-  The filename itself is in the rightmost column.
- The first column provides the permissions of the file, "r": read, "w": write, "x": execute. Hyphen (-) indicates that particular permission is denied.
- Permissions of a file can be changed using ```chmod``` system program. Like, ``` chmod g+w ls1.c ```
- The second column identifies the owner of the file
- The third column identifies the group of the file


This is not the whole information that Unix system maintains about each file. All of this information stored in tables managed by the system. The information can be accessed by using ```stat()``` function call.

```C
#include <stdio.h>
#include <sys/stat.h> /* needed for stat() function */
int main(int argc, char * argv[]) {
  struct stat fileinfo; // returned info about file
  int i;
  if (argc != 2){
  printf("Usage: statfile filename\n");
  exit(0);
  }
  i=stat(argv[1],&fileinfo);
  if (i == -1){
    printf("Unable to stat %s\n",argv[1]);
    exit(0);
    }
  printf("size: %d\n",fileinfo.st_size);
  printf("permissions: %d\n",fileinfo.st_mode);
  printf("last modified: %d\n",fileinfo.st_mtime);
  }
```

program never opens a file, however it calls ```stat()``` on the given filename. This is because the extra file information is not contained in the one-dimensional array of bytes that is the file; rather, it is maintained in tables managed by the system.
