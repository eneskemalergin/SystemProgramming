
	/* Draw the memory map for this code (pg 65) */

#include <stdio.h>

int main()
{
  char a,b,c;     // Initialize a, b, and c as char variable

  a = 7;          // Store 7 in a
  b = -13;        // Store -13 in b
  c = 0;          // Store 0 in c
}


/* Memory Map:
Char type occupies 1 byte so we need 3 byte memory

Label   Address     Value
a         400         7
b         401        -13
c         402         0

*/
