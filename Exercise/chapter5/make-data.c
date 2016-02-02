
	/* Create a file named "data.txt" to be used in subsequenc examples.
	** (pg 136) */

#include <stdio.h>

main()
{
FILE *fpt;

fpt=fopen("data.txt","w");
fprintf(fpt,"Fortytwo 42 bytes of data on the wall...");
fclose(fpt);
}
