
	/* Demonstrate fwrite() transporting bytes on a stream. (pg 140) */
	/* The file data2.txt will have the exact same contents as data.txt */

#include <stdio.h>

main()
{
FILE *fpt;
char text[80];

sprintf(text,"Fortytwo 42 bytes of data on the wall...");
fpt=fopen("data2.txt","w");
fwrite(text,1,strlen(text),fpt);
fclose(fpt);
}
