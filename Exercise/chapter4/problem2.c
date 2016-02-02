
	/* Code for problem 2 (pg 128) */

#include <stdio.h>

main()
{
double d[3],*e;
int i,*j;
char a,*b,c[3];

i=3;
j=&i;
d[0]=4.2;
e=&(d[1]);
*(e-1)=1.5;
e[1]=2.3;
for (i=0; i<5; i++)
  c[i%3]=(char)(*j+i);
b=&a;
*b=c[2];
}
