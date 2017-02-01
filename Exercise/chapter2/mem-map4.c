
	/* Draw the memory map for this code.  It can emphasize the
	** value of a loop counter after the loop is done (pg 67) */

#include <stdio.h>

int main()
{
  int i,n;              // Initialize i and n as integer variable

  n=0;                  // Store 0 in b
  for (i=1; i<=4; i++)  // Loop 4 times
    n=n+i;              // Increment n by i
}

/*
/1 represent strikethrough number

last value of i is 5
last value of n is 10

Label Address       Value
i     400–403   /1 /2 /3 /4 5
n     404–407   /0 /1 /3 /6 10

*/
