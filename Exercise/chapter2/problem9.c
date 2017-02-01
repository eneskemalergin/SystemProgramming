
	/* Code for problem #9 in chapter 2 (pg 70) */

#include <stdio.h>

int main()
{
  unsigned char x,y,z;

  x = 15;
  y = 35;
  z = 133;
  x = x|64;
  y = y&3;
  z = ~z;
  printf("%d %d %d\n",x,y,z);
}


/* Output of the program
79 3 122
*/
