
	/* This program shows basic array usage.
	** Draw the memory map. (pgs 74-75) */

#include <stdio.h>

main()
{
int a[2];	/* 2 cells, each cell 4 bytes (32 bits) */
float b[3];	/* 3 cells, each cell 4 bytes (32 bits) */
double c[4];	/* 4 cells, each cell 8 bytes (64 bits) */
char d[5];	/* 5 cells, each cell 1 bytes (8 bits) */

a[0]=5;
b[1]=4.0;
c[2]=14.7;
d[4]='a';
}

