---
Class  : Systems Programming
Date   : 03/30/2016
Author : Enes Kemal Ergin
Subject: Chapter 4 - Pointers and Structures
---

## Pointers
A pointer is a construct used to store an address of variable. We declare pointers using * (asterisk) symbol.

```C
char c,*cp;
int i,*ip;
float f,*fp;
double d,*dp;
```
Here is the memory map of the example above:

Label | Address | Value
----- | ------- | ----
c     | 400     |
cp    | 401–404 |
i     | 405–408 |  
ip    | 409–412 |  
f     | 413–416 |
fp    | 417–420 |
d     | 421–428 |
dp    | 429–432 |

In the example above we defined char c, integer i, float f, and double d; as well as the pointers cp, ip, fp, and dp, respectively in types.

- Every pointer/address requires 4 bytes.
- The ampersand symbol ```&``` indicates the “address of” a variable
- The asterisk symbol ```*``` indicates “at the address given by” a variable.

Let's practice on the concepts:

```C
cp=&c; // store the address of c in pointer cp
ip=&i; // store the address of i in pointer ip
*ip=42; //store the value 42 in ip's value's location

```

Here is the memory map of the example above:

Label | Address | Value
 ---  | ------- | ----
c     | 400     |
cp    | 401–404 |  400
i     | 405–408 |  42
ip    | 409–412 |  405
f     | 413–416 |
fp    | 417–420 |
d     | 421–428 |
dp    | 429–432 |


A pointer can hold address of any variable, including a cell in an array, for instance;

```C
char ca[3],*cp;
ca[1]=3;
cp=&(ca[1]);
*cp=7;
```
Here is the memory map of the example above:
Label | Address | Value
 ---  | ------- | ----
ca[0] |  400
ca[1] |  401    | 3 -> 7
ca[2] |  402
cp    |  403–406| 401



An address can be printed out using the printf() function in a few different ways. It is easier to read if it is printed as an unsigned int (using ```%u```) so that the number is always positive.

```C
char a,*b;
a=7; b=&a;
printf("%d %u %p value=%d\n",b,b,b,* b);


/* Output:
-1073764873 3221202423 0xbfffa5f7 value=7 */
```

For purposes of code design, it is convenient to use small numbers for addresses when writing a memory map, but during debugging, it may be necessary to work with large actual address values like these.

### Pointer Arithmetic
Pointer ```*``` sign has 2 different usage, first when to declare a pointer, and second during the variable usage.

- In the first case: the ```*``` symbol is indicating the variable type (pointer)
- In the second case: the ```*``` symbol is using the pointer to place a value at another address.

When adding or subtracting amounts from an address, pointer arithmetic acts in quantities of bytes equal to the size of the thing referenced. For example, consider the following code:

```C
char ca[3],*cp;
int ia[3],*ip;
cp=&(ca[0]);
ip=&(ia[0]);
```

Here is the memory map of the example above:
Label | Address | Value
 ---  | ------- | ----
ca[0]| 400|
ca[1]| 401|
ca[2]| 402|
cp   |403–406| 400
ia[0]| 407–410|
ia[1]| 411–414|
ia[2]| 415–418|
ip   |419–422| 407


Now consider the following lines of code involving pointer arithmetic:

```C
*(cp+2)=8;
*(ip+2)=33;
```

Pointer arithmetic uses the units of the type of variable “pointed to.” Since ```cp``` is a pointer to ```char```, its units are 1-byte increments. Since ```ip``` is a pointer to ```int```, its units are 4-byte increments.

```C
cp+2 = cp+2 (1 byte units) = 400+2 = 402
ip+2 = ip+2 (4 byte units) = 407+8 = 415
```

The resulting memory map after the pointer arithmetic:
Label | Address | Value
 ---  | ------- | ----
ca[0] | 400     |
ca[1] | 401     |
ca[2] | 402     | 8
cp    | 403–406 | 400
ia[0] | 407–410 |
ia[1] | 411–414 |
ia[2] | 415–418 | 33
ip    | 419–422 | 407

## Using Pointers
