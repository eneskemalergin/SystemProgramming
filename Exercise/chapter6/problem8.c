
	/* Code for problem 8 (pgs 207-208) */

#include <stdio.h>

#define MAX 5
#define MAGIC 9

main()
{
int n[MAX];
int i;

for (i=0; i<MAX; i++)
  {
  n[i]=i*i;
  printf("MAGIC = %d ? ",n[i]);
  if (n[i] == MAGIC)
    printf("yes\n");
  else
    printf("no\n");
  }
}

