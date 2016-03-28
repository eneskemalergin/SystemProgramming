---
Class  : Systems Programming
Date   : 02/01/2016
Author : Enes Kemal Ergin
Subject: Chapter 3 - Arrays and Strings
---

There are more data types in C; Arrays, Strings, Pointers, and Structures.

- Array: Lists the same type values
- String: They are basically text.
- Pointer: Address of another variable
- Structure: Group of mixed-type values.


## Arrays:

- Using only one variable name to set arrays.
- Each value in each position called _cell_
- Each cell occupies the same amount of memory space, since it stores the same type of values
- Here are some examples of memory space:

```C
int a[2]; // 2 cells, each cell 4 Bytes
float b[3]; // 3 cells, each cell 4 Bytes
double c[4]; // 4 cells, each cell 8 Bytes
char d[5]; // 5 cells each cell 1 Bytes
```

- When accessing an array index used should be 0 to 1 less than the total number of cells. _array bounds_.

### Multi-dimensional Arrays

```C
int a[3][2];
a[0][1] = 7;
a[1][0] = 13;

// Memory Map
/*
Label   |   Address   |   Value
a[0][0]     400-403       
a[0][1]     404-407         7
a[1][0]     408-411         13
a[1][1]     412-415
a[2][0]     416-419
a[2][1]     420-423
*/

```


## Strings
A string is a specific type of array contains only char with ```'\0'``` at the end.

```C
char d[8];
d[0]='H';
d[1]='e';
d[2]='l';
d[3]='l';
d[4]='o';
d[5]='\0'; // Represents the end of the string.

// Memory Map

/*
Label   |   Address   |   Value
d[0]          400          'H'
d[1]          401          'e'
d[2]          402          'l'
d[3]          403          'l'
d[4]          404          'o'
d[5]          405          '\0'
d[6]          406          
d[7]          407          
*/
```

- ```'\0'``` is a non printable character.
- In scanf and printf uses some data type identifier. ``` %c (char), %i or %d (int), %f (float), %lf (double)```
- But strings use ```%s``` because writing only "hello" is much easier other wise:

```C
printf("%c%c%c%c%c\n",d[0],d[1],d[2],d[3],d[4]);

// OR

printf("%s\n", d);


// Memory Map of using %s
/*
Address Label   |   Label   |   Address   |   Value
      d               d[0]        400          'H'
                      d[1]        401          'e'
                      d[2]        402          'l'                      
                      d[3]        403          'l'
                      d[4]        404          'o'
                      d[5]        409           0
                      d[6]        408          
                      d[7]        407                                                                          
*/
```
This is very frusturating.  

---

### String Library Functions
Here are some string library functions in the C standard library.

- ```strlen()```  : count the total character in the given string
- ```strcmp()```  : compare the two string and determine if they identical
- ```strcat()```  : adds one string to another
- ```strcpy()```  : basic copying from one string to another
- ```sprintf()``` : print formatted output into a string variable

Now we will examine them closely...

#### String Length: strlen()
This function counts the character for given string.


```C

// Without using library we can count the character like following
int length;
char s[6];
s[0]='S'; s[1]='u'; s[2]='e'; s[3]='\0';
length=0;
while (s[length] != '\0')
length++;

// With string library
#include<string.h>
length=strlen(s);

```

In the example above we see ```'\0'``` character at the end of the string value represented by array. This character is known as _sentinel_ or _flag_ The value of a sentinel is not intended to be used in a computation; rather, it is intended to terminate the processing of a list of data.


#### String Compare: strcom()
This function compare two given strings and say that if they are identical, if not it will which string first reaches an index having a value less then the same index in the other string.

```C

// Without using library
int i,a;
char s[4],t[4];
s[0]='S'; s[1]='u'; s[2]='e'; s[3]='\0';
t[0]='S'; t[1]='u'; t[2]='n'; t[3]='\0';
i=0; a=0;
while (a == 0)
{
if (s[i] < t[i]) a=-1;
if (s[i] > t[i]) a=1;
if (s[i] == '\0' || t[i] == '\0')
break;
i++;
}

// With library usage
#include<string.h>
a=strcmp(s,t);
```

#### String Copy: strcpy()
This function copies the contents of a string to a second string variable.

```C
// Without using library
int i;
char s[4],t[4];
s[0]='S'; s[1]='u'; s[2]='e'; s[3]='\0';
i=0;
while (s[i] != '\0')
{
t[i]=s[i];
i++;
}
t[i]='\0';

// With library usage
#include<string.h>
strcpy(t,s);
```

#### String Concatenate: strcat()
This function appends a string (the addendum) to the end of another string (the original).

```C

// Without using library
int i,j;
char s[8],t[4];
s[0]='S'; s[1]='u'; s[2]='\0';
t[0]='s'; t[1]='a'; t[2]='n'; t[3]='\0';
i=strlen(s);
j=0;
while (t[j] != '\0')
{
s[i+j]=t[j];
j++;
}
s[i+j]='\0';

// With library usage
```

In ```strcat()``` there are two things we need to remember:

>
  - The original string comes first in the argument list; the addendum string comes second.   
  - The result is placed in the original string variable.

#### String Print: springf()
The ```sprintf()``` function works just like the printf() function, except that the output __“prints” into a string variable.__ This can be useful _for converting numeric data types into ASCII text_, or _for creating long strings from multiple components._

```C
#include<stdio.h>
#include<string.h>
char a[24];
float f;
int i;
f=3.72;
i=9;
sprintf(a,"Price %f, qty %d",f,i);
printf("%s\n",a);
```


We are ending here for this topic on string library functions, there are more function in string library, however the ones we covered are the ones are the popular ones.

> Before finishing this topic I would like to emphasize something very important. There are tons of problems out there that requires you to write your own functions even libraries. So use libraries to fasten your production but don't completely depend on them.

---

### Command Line Arguments

```Bash
ahoover@video> ls -l -t
drwxr-xr-x 26 ahoover fusion 4096 Jul 20 16:03 ece222/
drwxr-xr-x 7 ahoover 325 4096 Jul 19 17:01 public_html/
drwx------ 2 ahoover fusion 4096 Feb 7 14:33 mail/
drwxr-xr-x 3 ahoover fusion 4096 Dec 14 2005 ece854/
drwxr-xr-x 3 ahoover fusion 4096 Dec 14 2005 ece429/
drwxr-xr-x 2 ahoover fusion 4096 Mar 19 2005 ece893/
drwxr-xr-x 3 ahoover fusion 4096 Mar 19 2005 ece468/
drwxr-xr-x 15 ahoover fusion 4096 Dec 14 2005 Projects/
ahoover@video>
```

The example above show the special listing in command line which is enriched by arguments ```-l``` and ```-t```. ```-l``` arguments lists with more detail. ```-t``` argument order them by their last accessed/used times.

So the question here is how the program understands command line arguments. In C language we use full main function declaration which looks like this: ```int main(int argc, char *argv[])``` Lets examine this function call.

- The variable ```argc``` stores the number of command line arguments, including the name of the program, like we did in ``` ls -l -t```
- The variable ```argv``` stores a list of strings, one string per command line argument.

The following code will demonstrate how to print out all the command line arguments given by user.

```C
int main(int argc, char *argv[]){
int i,j;
for (i=0; i<argc; i++)
{
j=0;
while (argv[i][j] != '\0')
{
printf("%c",argv[i][j]);
j++;
}
printf("\n");
}
}
```

Each string can be accessed through its own address label, so that the code example just given can be simplified as follows:

```C
for (i=0; i<argc; i++)
  printf("%s\n",argv[i]);
```
---

> End of Chapter
> Revision 1: 03/28/16
