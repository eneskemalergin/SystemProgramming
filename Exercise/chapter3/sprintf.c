
	/* Print formatted output into a string (pgs 88-89) */

#include <stdio.h>
#include <string.h>

main()
{
char a[24];
float f;
int i;

f=3.72;
i=9;
sprintf(a,"Price %f, qty %d",f,i);
printf("%s\n",a);
}
