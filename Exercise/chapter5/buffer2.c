
	/* The type of buffering in the first example can be determined
	** by adding a newline character to the output (pg 144) */

#include <stdio.h>

main()
{
int i;

for (i=0; i<5; i++)
  {
  printf("i=%d\n",i);	/* with newline character, we see line buffering */
  sleep(1);		/* pauses program for 1 second */
  }
}
