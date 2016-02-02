
	/* Demonstrate the creation, use, and closing of a stream. (pg 136) */

#include <stdio.h>

main()
{
FILE *fpt;

fpt=fopen("output.txt","w");		/* create a stream */
fprintf(fpt,"This is a test.");		/* transport bytes on the stream */
fclose(fpt);				/* close the stream */
}
