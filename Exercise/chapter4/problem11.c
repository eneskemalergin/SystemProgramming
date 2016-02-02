
	/* Code for problem 11 (pgs 130-131) */

#include <stdio.h>

main()
{
struct ID {
	  int number;
	  float cost;
	  double *barcode;
	  };
struct ID list[3],*item;
float *f;
double *d,d2;

d2=888;
list[2].number=12;
list[2].cost=44.11;
list[2].barcode=&d2;
item=&(list[2]);
f=&(item->cost);
d=item->barcode;
*d=(*d)+1;
}
