
	/*
	** Code to introduce array of structs.  Also looks at some
	** ways to get addresses of a struct or its parts. (pg 121)
	*/

#include <stdio.h>

struct person {			/* "person" is name for structure type */
	char	first[32];	/* first field of structure is array of char */
	char	last[32];	/* second field is array of char */
	int	year;		/* third field is int */
	double	ppg;		/* fourth field is double */
	};		/* ending ; means end of structure type definition */


int main(int argc,char *argv[])

{
struct person	teacher;
int		i;

teacher.year=2005;
teacher.ppg=10.4;
strcpy(teacher.first,"Adam");
strcpy(teacher.last,"Hoover");

demo_function();
}


demo_function()

{
struct person	class[54];	/* array of "person" structs */

class[0].year=2004;	/* notice where array subscript goes */
class[0].ppg=5.2;

strcpy(class[0].first,"Jane");
strcpy(class[0].last,"Doe");

printf("year: %d   points per game: %lf\n",class[0].year,class[0].ppg);

printf("%c\n",class[0].first[2]);

strcpy(class[1].first,"Brian");
strcpy(class[1].last,"Smith");

printf("%c\n",class[0].last[45]);	/* an array of structs is contiguous */
printf("%c\n",class[0].last[77]);	/* in memory */

			/* what do you expect to see for each of these? */
printf("address of class: %u\n",&(class));
printf("address of class[0]: %u\n",&(class[0]));
printf("address of class[0].first: %u\n",&(class[0].first));
printf("address of class[0].last: %u\n",&(class[0].last));
printf("address of class[0].year: %u\n",&(class[0].year));
printf("address of class[0].ppg: %u\n",&(class[0].ppg));
printf("address of class[1].first: %u\n",&(class[1].first));
}
