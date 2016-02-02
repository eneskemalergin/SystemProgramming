
	/* Code for problem 4 (pg 206) */

#include <stdio.h>

int x;

int Magic(int z)
{
z=x*3;
return(z);
}

int main()
{
int y;
x=4;
y=6;
x=Magic(y);
printf("%d %d\n",x,y);
}

