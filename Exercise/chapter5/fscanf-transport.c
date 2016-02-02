
	/* Show how fscanf() not only transports bytes on a stream, but
	** also change manipulate the bytes during the transport (pg 139) */

#include <stdio.h>

main()
{
FILE *fpt;

char text[30];
int x;
fpt=fopen("data.txt","r");
fscanf(fpt,"%s",text);
fscanf(fpt,"%d",&x);
fclose(fpt);
}
