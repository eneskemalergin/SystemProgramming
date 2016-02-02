
	/* Demonstrate fread() transporting bytes on a stream. (pg 138) */

#include <stdio.h>

main()
{
FILE *fpt;

char text[80];
fpt=fopen("data.txt","r");
fread(text,1,15,fpt);
text[15]=0;
printf("%s\n",text);
fclose(fpt);
}
