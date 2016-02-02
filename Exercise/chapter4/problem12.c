
	/* Code for problem 12 (pg 131) */

#include <stdio.h>

main()
{
struct passport {
		char last[10];
		int number;
		float fees;
		double *country_code;
		};
struct passport list[3],*passenger;
char who[7],a,*b;
double *d,d2;
int i,*j;

d2=888;
i=12;
j=&i;
strcpy(who,"person");
strcpy(list[1].last,"jones");
list[1].number=129783;
list[1].fees=105.37;
list[1].country_code=&d2;
passenger=&(list[1]);
b=&(passenger->last[0]);
d=passenger->country_code;
*b='t';
passenger->last[4]='y';
for (i=0; i<5; i++)
  who[i%3]=(char)(*j+i);
}
