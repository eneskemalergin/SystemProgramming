
	/* This program demonstrates right-shifting a negative integer
		** so that the shifted-in bits are 1 instead of 0 (pg 62) */

#include <stdio.h>

int main()
{
char a,b;

a = 17;
a = a >> 2;
b = -65;
b = b >> 3;
printf("%d %d\n",a,b);
}
