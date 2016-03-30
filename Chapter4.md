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
Under this title we will see how we can use pointers.

### Passing Values Back from a Function
The most common reason for using pointers is to pass values back from a function. Let's examine the following practice during this section:

```C
#include<stdio.h>
int division(int numerator, int denominator, int * dividend, int * remainder)
{
  printf("address stored in dividend: %u\n",dividend);
  printf("address stored in remainder: %u\n",remainder);
  if (denominator == 0)
    return(0);
  * dividend=numerator/denominator;
  * remainder=numerator%denominator;

    return(1);
}
int main()
{
  int x,y,d,r;
  x=9;
  y=2;
  printf("address of d: %u\n",&d);
  printf("address of r: %u\n",&r);
  division(x,y,&d,&r);
  printf("%d/%d = %d with %d remainder\n",x,y,d,r);
  printf("x=%d\n",x);
}
```

The resulting memory map:

Label | Address | Value
 ---  | ------- | ----
numerator |400–403|
denominator |404–407|
dividend |408–411|
remainder |412–415|
x |700–703|
y |704–707|
d |708–711|
r |712–715|

- The parameters of the ```division()``` function are variables, so they must be included in the memory map.
- The addresses used for the ```main()``` function (700’s) have been somewhat separated from those used for the ```division()``` function (400’s),for sake of simplicity.
- The size of every variable is 4 bytes, because they are all either int or pointer variables.

Let's examine the steps deeply by going slowly on execution:

-  Code execution starts
- The values 9 and 2 go into ```x``` and ```y```
- Function call and copying of all variables

let's see the memory map from this point:

Label | Address | Value
 ---  | ------- | ----
numerator | 400–403 |  9
denominator | 404–407 | 2
dividend | 408–411 | 708
remainder | 412–415 | 712
x | 700–703  |9
y | 704–707 | 2
d | 708–711 |
r | 712–715 |

- ```x``` and ```y``` are copied to ```numerator``` and ```denominator``` after calling the function.
- it is the addresses of ```d``` and ```r``` that are copied to ```dividend``` and ```remainder```, too

Let's see how d and r changed in memory maps:

Label | Address | Value
 ---  | ------- | ----
numerator | 400–403  | 9
denominator | 404–407|  2
dividend|  408–411 | 708
remainder|  412–415 | 712
x | 700–703|  9
y | 704–707| 2
d | 708–711 |4
r | 712–715 |1

- results are never in any local memory location for the ```division()``` function, they are stored only in the original ```main()``` function variables.

### Pointers and Arrays
The second most common use of a pointer is when an array is used. Arrays are pointers, in so far as they are both addresses. In this section we will show how arrays and pointers can be used interchangeable. Let's check the following example:

```C
#include <stdio.h>
int main()
{
  double array[5];
  double * d_ptr;
  double value;
  int i,offset;

  for (i=0; i<5; i++)
    array[i]=(double)i+10.0;

  d_ptr=&(array[0]);

  while (1)
  {
    printf("Address(hex)\tAddress(base10)\tValue\n");
    for (i=0; i<5; i++)
      printf("%p\t%u\t%lf\n",&(array[i]),&(array[i]),array[i]);
    printf("Enter offset value (0 0 to quit): ");
    scanf("%d %lf",&offset,&value);
    if (offset == 0 && value == 0.0)
      break;
    if (offset < 0 || offset > 4)
    {
      printf("Offset out of bounds\n");
      continue;
    }
    array[offset]=value;
    * (d_ptr+offset)=value;
    * (array+offset)=value;
  }
}
```

In the last three lines of code shows how to access the same memory using array indexing, pointer arithmetic, or even a mix of both. All three of those lines of code do the exact same thing. We can see this by looking at the memory map:


Address Label | Label | Address | Value
------------- | ----- | ------- | -----
array &(array[0])| array[0] | 400–407  | 10.0
| array[1]  | 408–415 | 11.0
| array[2] | 416–423 | 12.0
| array[3] | 424–431 | 13.0
| array[4] | 432–439 | 14.0
| d_ptr   | 440–443 | 400
| value   | 444–451 |
| i       | 452–455 | 0 -> 1 -> 2 -> 3 -> 4 -> 5
| offset  | 456–459 |

- The value at address 400 can be accessed through its original name ```array[0]```, or through the pointer value of ```d_ptr```, or through mixed notation using a pointer to the original address label array.
- It can even be accessed using another mixed notation based on the other original address label ```&(array[0])```:

```C
*(&(array[0])+offset)=value;
```

### Dynamic Memory Allocation
Variables are normally given space through static memory allocation. This means that the size (in bytes) of each of the variables is known before the program runs.

Sometimes a program does not know how much memory it needs prior to execution. For example, in reading a line of text from a file, the program might not know how big a string is needed to store all the words before the particular file has been selected, and read.

In such cases defining a sufficient(!) size string, this approach is wasteful and in some cases impossible, since knowing the size of upcoming data is impossible in most cases.

The alternative is to use dynamic memory allocation.

Dynamic memory allocation uses a pointer variable to request memory from the O/S while the program is running. The basic function call for dynamic memory allocation is ```malloc()```, and works as follows:

```C
#include <stdlib.h>  // To use malloc()
double *a;
a = (double *) malloc (40); // Putting the size as bytes 40byte in this case..
```

- The typecast identifies the type of pointer arithmetic expected for the address returned from ```malloc()```.
- The malloc() function call is the request to the O/S for memory.
-  It takes one parameter, which is the number of bytes needed. (40 Bytes in the example above, 5 double)


How does it work?

- A ```malloc()``` call asks the O/S for a chunk of memory of the given size
- The chunk of memory is obtained from an area of memory called the heap.
- The heap can normally support larger variables.


Memory Map of example above:

Label | Address | Value
 ---  | ------- | ----
a     | 400–403 | 10000
[DM]  | 10000–10039 |

- Dynamically allocated memory does not have an existing label, so we use [DM] to temporarily provide it a name
- In order to give it a name that our program can use, we must use either pointer or array syntax based upon the variable a.
- Either syntax can be used to address, or label, different parts of the 40 bytes requested. For example:

```C
a[0]=8;
*(a+2)=3;
a[3]=9;
```

Memory Map of the example:

Label | Address | Value
 ---  | ------- | ----
a  | 400–403 | 10000
*(a+0) a[0] |  10000–10007 |8
*(a+1) a[1] | 10008–10015 |
*(a+2) a[2] | 10016–10023 | 3
*(a+3) a[3] | 10024–10031 | 9
*(a+4) a[4] | 10032–10039 |

)*

Every cell of memory in the chunk of bytes has both a pointer-based label and an array-based label and can be accessed using either syntax. It is quite common to see a pointer variable used for dynamic memory allocation and then accessed using array syntax.

Every time a function ends, its statically declared memory is released from the stack and returned to the O/S. But it is different in dynamic memory location. We have to free the memory by using ```free()``` function.

```C
free(a);
```

Failure to call the ```free()``` function appropriately may result in a program losing track of the memory it uses. Sometimes this is referred to as a memory leak. For example:

```C
double *a;
a=(double *)malloc(70);
a=(double *)malloc(300); /* memory leak */
```

The second request without closing the first one in the same location cause and overwrite, which leads to memory loss from the first attempt.

### Double Pointers
