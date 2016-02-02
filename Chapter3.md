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


### String Library Functions
