
	/* This file goes with ext1.c to demonstrate globals (pgs 195-196) */

#include <stdio.h>

extern int x;

void function()
{
printf("function: %d\n",x);
x=7;
printf("function: %d\n",x);
}

