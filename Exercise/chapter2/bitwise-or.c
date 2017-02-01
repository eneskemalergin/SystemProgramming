
	/* This program demonstrates the bitwise or operator. (pg 60) */

#include <stdio.h>

int main()
{
  unsigned char a,b;    // Initialize a and b as unsigned char variable

  a = 17;               // Add 17 to a           -> 0 0 0 1 0 0 0 1
  b = 22;               // Add 22 to b           -> 0 0 0 1 0 1 1 0
  a = a | b;            // Bitwise OR of a and b -> 0 0 0 1 0 1 1 1
  printf("%d\n",a);     // Print the value of a
}

// Result:
// 23
