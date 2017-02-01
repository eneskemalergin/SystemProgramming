
	/* This program demonstrates the bitwise shift operators,
	** left-shift and right-shift. (pg 61) */

#include <stdio.h>

int main()
{
  unsigned char a,b;      // Initialize a and b as unsigned char variable

  a = 17;                   // Store 17 in a    -> 0 0 0 1 0 0 0 1
  a = a << 2;               // Left shift by 2  -> 0 1 0 0 0 1 0 0
  b = 64;                   // Store 64 in b    -> 0 1 0 0 0 0 0 0
  b = b >> 3;               // Right shift by 3 -> 0 0 0 0 1 0 0 0
  printf("%d %d\n",a,b);    // Print last values of a and b
}

// Result
// 68 8
