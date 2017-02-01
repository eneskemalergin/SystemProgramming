
	/* Code for problem #12 in chapter 2 (pg 70) */

#include <stdio.h>

int main()
{
  int i,j;

  j=0;
  for (i=1; i<100; i=i<<1)
    {
    if (i % 5 > 1)
      j=j | i;
    printf("%d %d\n",i,j);
    }
}

/* Output
1 0
2 2
4 6
8 14
16 14
32 46
64 110

*/
