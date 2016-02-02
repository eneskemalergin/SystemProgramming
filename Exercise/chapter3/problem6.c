
	/* Code for problem 6 (pg 96) */

#include <stdio.h>
#include <string.h>

main()
{
char s[10],t[10];
int i,j;

strcpy(s,"frog");
for (i=0; i<strlen(s); i++)
  t[i]=s[i];
j=0;
for (i=0; i<strlen(t); i++)
  j=j+(int)t[i];
printf("%d\n",j);
}
