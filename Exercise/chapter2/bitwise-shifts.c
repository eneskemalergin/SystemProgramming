
	/* This program demonstrates the bitwise shift operators,
	** left-shift and right-shift. (pg 61) */

#include <stdio.h>

main()
{
unsigned char a,b;

a=17;
a=a << 2;
b=64;
b=b >> 3;
printf("%d %d\n",a,b);
}
