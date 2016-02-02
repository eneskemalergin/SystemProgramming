
	/* Demonstrate global variables and extern keyword (pgs 195-196) */
	/* Use this file (ext1.c) with second file (ext2.c). */

#include <stdio.h>

int x;

int main(int argc, char *argv[])
{
x=1;
printf("main: %d\n",x);
function();
printf("main: %d\n",x);
}

