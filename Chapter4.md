---
Class  : Systems Programming
Date   : 03/28/2016
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
