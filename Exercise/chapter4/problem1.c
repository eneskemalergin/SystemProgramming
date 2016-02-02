
	/* Code for problem 1 (pg 127) */

#include <stdio.h>

main()
{
char a,*b,c[3];
int i,*j,k[3];

a='N'
b=&(c[2]);
j=&(k[0]);
for (i=0; i<3; i++)
  {
  *b=a-(char)i;
  b--;
  *j=i+5;
  j++;
  }
}
