
	/* This program accesses an invalid array cell.  It compiles,
	** but seg-faults on exection.  Draw the memory map. (pg 77) */

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

b[33333]=15.9;
printf("%lf\n",b[33333]);
}

