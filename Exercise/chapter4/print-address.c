
	/* Print out the value of a pointer value (an address). (pg 106) */

#include <stdio.h>

main()
{
char a,*b;

a=7;
b=&a;
printf("%d %u %p value=%d\n",b,b,b,*b);
}
