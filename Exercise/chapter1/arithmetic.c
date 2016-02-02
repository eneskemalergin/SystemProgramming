
	/* A review of the basic arithmetic operators in C.  (pg 37) */

#include <stdio.h>

int main()
{
int x,y;
int r1,r2,r3,r4,r5;

x=4;
y=7;
r1=x+y;
r2=x-y;
r3=x/y;
r4=x*y;
printf("%d %d %d %d\n",r1,r2,r3,r4);

r3++;
r4--;
r5=r4%r1;
printf("%d %d %d\n",r3,r4,r5);
}
