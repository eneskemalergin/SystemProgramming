
	/* Demonstrate file I/O concepts on terminal device (pgs 161-162) */
	/* NOTE: Use tty program to determine the name of the terminal in
	** which you are running programs, and replace /dev/pts/1 with
	** that name. */

#include <stdio.h>

main()
{
FILE *fpt;

fpt=fopen("/dev/pts/1","w");
fprintf(fpt,"Hello terminal.");
fclose(fpt);
}

