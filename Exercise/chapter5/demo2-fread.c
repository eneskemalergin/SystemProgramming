
	/* Demonstrate how fread() (and fwrite()) return the number of bytes
	** successfully moved on the stream (pgs 140-141) */

#include <stdio.h>

main()
{
FILE *fpt;
char text[80];
int bytes_read;

fpt=fopen("data.txt","r");
bytes_read=fread(text,1,70,fpt);
printf("%d\n",bytes_read);
fclose(fpt);
}
