
	/* Demonstrate fscanf() transporting bytes on a stream. (pg 137) */

#include <stdio.h>

main()
{
FILE *fpt;

char text[80];
fpt=fopen("data.txt","r");
fscanf(fpt,"%s",text);
printf("%s\n",text);
fclose(fpt);
}
