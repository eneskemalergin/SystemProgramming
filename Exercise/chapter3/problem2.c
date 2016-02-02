
	/* Code for problem 2 (pg 94) */

#include <stdio.h>

main()
{
int a[4],i;
float b[3];
char c[3];
double d[4];

b[2]=6.7;
for (a[0]=2; a[0]>0; a[0]--)
  b[a[0]-1]=b[a[0]]+2.3;
c[1]='N';
d[0]=12.6;
for (i=1; i<3; i++)
  d[i]=d[0]+(double)b[i];
}
