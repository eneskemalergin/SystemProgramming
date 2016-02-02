
	/* Demonstrate the effect of buffering (pg 144) */

#include <stdio.h>

main()
{
int i;

for (i=0; i<5; i++)
  {
  printf("i=%d ",i);
  sleep(1);		/* pauses program for 1 second */
  }
}
