
	/* This program demonstrates right-shifting a negative integer
		** so that the shifted-in bits are 1 instead of 0 (pg 62) */

#include <stdio.h>

int main()
{
  char a,b;             // Initialize a and b as char type variable

  a = 17;               // Store value 17 in a
  a = a >> 2;           // Apply right shift which shifts the binary 2 unit to right
  b = -65;              // Store value -65 in b
  b = b >> 3;           // Apply right shift which shifts the binary 3 unit to right
  printf("%d %d\n",a,b);// Print the changed values as integer
}
