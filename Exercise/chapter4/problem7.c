
	/* Code for problem 7 (pg 129) */

#include <stdio.h>

struct comp {
	    char address[80];
	    char phone[11];
	    } tc;
struct inv  {
	    char barcode[12];
	    float price;
	    struct comp *manuf;
	    };

main()

{
struct inv s;

sprintf(tc.address,"313 Main St.");
strcpy(tc.phone,"3035552479");
s.price=6.42;
strcpy(s.barcode,"1961354128");
s.manuf=&tc;
printf("%c %s\n",s.manuf->address[5],&(tc.phone[6]));
}
