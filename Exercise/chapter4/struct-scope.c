
	/*
	** Code to demonstrate global and local struct variables.  They
	** work just like the other data types. (pg 123)
	*/

#include <stdio.h>

struct fraction {		/* structure type name AND variable name */
	int	x,y;
	} global;		/* a variable outside a function is global */

main()

{
	/* a structre template can be "throw away" (used only once) */
struct {			/* notice there is no name for structure type */
	char	title[20];
	float	cost;
	} paperback;
int	n;
struct fraction local;

n=3;
paperback.cost=4.50;
	/* sprintf() prints text to a string */
sprintf(paperback.title,"Calvin & Hobbes %d",n);

printf("cost:  %f    title:  %s\n",paperback.cost,paperback.title);

strcpy(paperback.title,"Calvin & Hobbes Field Trip");

	/* why does the following line print strangely? */
printf("cost:  %f    title:  %s\n",paperback.cost,paperback.title);

main2();

	/* what values do we expect to see printed here? */
printf("%d %d\n",global.x,local.x);
}


main2()

{
struct fraction local,x;	/* field names are independent of variables */

global.x=1;
local.x=2;
x.x=3;				/* so "x" can be a variable and field name */
printf("%d %d %d\n",global.x,local.x,x.x);
}
