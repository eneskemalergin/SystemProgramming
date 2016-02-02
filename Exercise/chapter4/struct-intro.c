
	/*
	** Code to introduce structure, its use, and how it looks in memory.
	** Construct a memory map to go with it. (pgs 118-119)
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

printf("year: %d   points per game: %lf\n",teacher.year,teacher.ppg);

printf("%c\n",teacher.first[3]);
for (i=0; i<7; i++)
  printf("%d %c\n",teacher.last[i],teacher.last[i]);

printf("%c %c\n",teacher.last[6],teacher.last[9]);
printf("%d\n",teacher.last[6]);

printf("%c %c\n",teacher.first[32],teacher.first[33]);

}

