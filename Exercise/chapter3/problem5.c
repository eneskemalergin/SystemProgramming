
	/* Code for problem 5 (pg 95) */

#include <stdio.h>

main()
{
int i,j,t;
char name[50];

printf("What is your name? ");
scanf("%s",name);
t=0;
for (i=0; i<strlen(name); i++)
  for (j='a'; j<=name[i]; j++)
    t++;
printf("%d\n",t);
}
