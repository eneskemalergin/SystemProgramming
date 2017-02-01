
	/* This program demonstrates using the bitwise operators
	** with variables and constants. (pg 61) */

#include <stdio.h>

int main()
{
  char x,y;               // Initialize x and y as char variable

  x = 7;                  // Store 7 in x                 -> 0 0 0 0 0 1 1 1
  y = 6;                  // Store 6 in y                 -> 0 0 0 0 0 1 1 0
  x = x&y;                // Store result of x and y in x -> 0 0 0 0 0 1 1 0
  y = x|16;               // Store result of x or 16 in y -> 0 0 0 1 0 1 1 0
  printf("%d %d\n",x,y);  // Print the value of x and y
}

/* Result:
6 22
 */
