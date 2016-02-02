
	/* Code for problem #12 in chapter 2 (pg 70) */

#include <stdio.h>

main()
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

