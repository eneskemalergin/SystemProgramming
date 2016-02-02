
	/* Introduce nested structures. (pg 124-125) */

#include <stdio.h>

struct name {
	char	first[30];
	char	last[30];
	};

struct person {
	int		age;
	float		ppg;
	struct name	title;		/* nested structure */
	};				/* `name' must be defined above */

main()

{
struct person	boss;
float		adam_ppg;
boss.age=40;
boss.ppg=adam_ppg-9.3;

strcpy(boss.title.first,"Dean");
strcpy(boss.title.last,"Keinath");

printf("%c\n",boss.name.first[0]);

printf("%c\n",boss.title.first[0]);

printf("%c\n",boss.title[0]);
	
printf("%u\n",boss.title);

printf("%u\n",&(boss.title));

printf("%u\n",&(boss.title.first[0]));
}

