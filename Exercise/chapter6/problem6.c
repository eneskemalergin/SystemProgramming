
	/* Code for problem 6 (pg 207) */

#include <stdio.h>

typedef struct amount {
		      int dollars;
		      char cents;
		      } money;

main()
{
money a,*b;

a.dollars=1;
a.cents=99;
b=&a;
b->cents=75;
}

