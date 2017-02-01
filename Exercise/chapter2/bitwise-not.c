
	/* This program demonstrates the bitwise not operator. (pg 59) */

#include <stdio.h>

int main()
{
  unsigned char a;      // Initialize a as unsigned char

  a = 17;               // Store 17 in a                 -> 0 0 0 1 0 0 0 1 , 17
  a = ~a;               // Store the value of NOT a in a -> 1 1 1 0 1 1 1 0 , 238
  printf("%d\n",a);     // Print the new value of a
}

// Result
// 238
