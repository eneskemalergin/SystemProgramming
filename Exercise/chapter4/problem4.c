
	/* Code for problem 4 (pg 128) */

#include <stdio.h>

main()
{
int *p;

funct(p);
printf("%d\n",*p);
}

funct(int *p2)
{
p2=(int *)malloc(4);
*p2=14;
printf("%d\n",*p2);
}
