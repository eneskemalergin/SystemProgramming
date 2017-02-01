
	/* This program demonstrates the bitwise and operator. (pg 60) */

#include <stdio.h>

int main()
{
  unsigned char a,b;      // Initialize a and b as unsigned char variable

  a = 17;                   // Store 17 in a            -> 0 0 0 1 0 0 0 1
  b = 22;                   // Store 22 in b            -> 0 0 0 1 0 1 1 0
  a = a & b;                // Store result of a and b  -> 0 0 0 1 0 0 0 0
  printf("%d\n",a);         // Print the result of new a
}

// Result:
// 16
