
	/* Code for problem 1 (pg 94) */

#include <stdio.h>

main()
{
int i,j,k,swap;
char c[8];

c[0]='f'; c[1]='r'; c[2]='o'; c[3]='g'; c[4]=0;
for (i=0; i<4; i++)
  {
  k=i;
  for (j=i+1; j<4; j++)
    if (c[j]-c[k] < 10)
      k=j;
  swap=c[i];
  c[i]=c[k];
  c[k]=swap;
  }
}
