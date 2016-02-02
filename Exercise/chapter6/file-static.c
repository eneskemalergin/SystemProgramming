
	/* Demonstrate file-static variable scope (pgs 193-194) */

#include <stdio.h>

static int sq=0;

int summer(int x)
{
static int sum=0;

sum=sum+x;
sq=sq-1;
return(sum);
}

main()
{
int i,j;

for (i=0; i<5; i++)
  {
  sq=sq+(i*i);
  j=summer(i);
  printf("%d %d\n",j,sq);
  }
}

