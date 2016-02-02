
	/* This program demonstrates using the bitwise operators
	** with variables and constants. (pg 61) */

#include <stdio.h>

main()
{
char x,y;

x=7;
y=6;
x=x&y;
y=x|16;
printf("%d %d\n",x,y);
}
