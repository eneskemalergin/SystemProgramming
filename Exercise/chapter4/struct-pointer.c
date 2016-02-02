
	/* Introduce pointers to structures, including -> syntax 
	** (pgs 125-127) */

#include <stdio.h>

struct item {			/* structure type name AND variable name */
	char	name[80];
	int	year;
	float	cost;
	} bad_habit;

main()

{
struct item	book;
struct item	*journal;

book.year=1985;

journal.year=1992;

journal=(struct item *)calloc(1,sizeof(struct item));

journal->year=1992;		/* `->' symbol for access to fields of */
journal->cost=238.55;		/*  pointer to struct (instead of `.') */

strcpy(journal->name,"IEEE Transactions on PAMI");

printf("%c\n",journal->name[5]);
}


