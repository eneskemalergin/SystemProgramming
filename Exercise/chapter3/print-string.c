
	/* This program shows how a string is printed.  Walk through
	** the memory map. (pgs 80-81) */

#include <stdio.h>

main()
{
char d[8];

d[0]='H'; d[1]='e'; d[2]='l'; d[3]='l'; d[4]='o';
d[5]=0; 		/* integer zero */

printf("%c%c%c%c%c\n",d[0],d[1],d[2],d[3],d[4]);

printf("%s\n",d);
}

