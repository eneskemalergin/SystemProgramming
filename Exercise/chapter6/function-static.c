
	/* Demonstrate static variable scope (pgs 192-193) */

#include <stdio.h>

int summer(int x)
{
static int sum=0;

sum=sum+x;
return(sum);
}

main()
{
int i,j;

for (i=0; i<5; i++)
  {
  j=summer(i);
  printf("%d\n",j);
  }
}

