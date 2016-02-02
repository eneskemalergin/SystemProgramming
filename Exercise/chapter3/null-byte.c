
	/* This program shows different aliases for the NULL byte (pg 80) */

#include <stdio.h>

main()
{
char d[8];

d[0]='H'; d[1]='e'; d[2]='l'; d[3]='l'; d[4]='o';
d[5]='\0'; 		/* ASCII zero */
d[5]=0; 		/* integer zero */
d[5]=(char)NULL; 	/* address zero */
}

