
	/* Code for problem #13 in chapter 2 (pg 71) */

#include <stdio.h>

main()
{
int i,j,k;

j=0;
k=32;
for (i=100; i>0; i-=10)
  {
  if (k/4 > 0)
    j=j | k;
  if (i <= 70 && i >= 40)
    k=k<<1;
  else
    k=k>>1;
  printf("%d %d %d\n",i,j,k);
  }
}

