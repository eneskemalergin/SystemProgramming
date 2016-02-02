
	/* A review of conditionals and blocks in C.  (pg 39) */

#include <stdio.h>

int main()
{
int i,x;

x=0;
for (i=0; i<5; i++)
  {
  if (i%2 == 0 || i == 1)
    x=x+i;
  else
    x=x-i;
  printf("%d\n",x);
  }
}

