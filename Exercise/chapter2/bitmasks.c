
	/* This program demonstrates setting a bit, clearing a bit, and
	** reading a bit. (pg 64) */

#include <stdio.h>

int main()
{
  char a;                           // Initialize a as char variable
  int i;                            // Initialize i as integer variable

  // a = 17 -> 0 0 0 1 0 0 0 1
  a = 17;                             // Store 17 in char variable a

  /* set 3rd bit */
  // 0 0 0 1 1 0 0 1
  a = a | (1 << 3);

  printf("%d\n",a);                   // Print the value of a

  /* clear 4th bit */
  // 0 0 0 0 1 0 0 1
  a = a & (~(1<<4));

  printf("%d\n",a);                   // Print the value of a

  for (i=7; i>=0; i--)                // Loop through the bitwise model
    printf("%d ",(a&(1<<i)) >> i);    // Read the i'th bit in a
  printf("\n");
}

/* Result:
25
9
0 0 0 0 1 0 0 1
*/
