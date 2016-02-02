
	/* Comparing two strings (pg 85) */

#include <stdio.h>
#include <string.h>

main()
{
int i,a;
char s[4],t[4];

s[0]='S'; s[1]='u'; s[2]='e'; s[3]='\0';
t[0]='S'; t[1]='u'; t[2]='n'; t[3]='\0';
i=0; a=0;
while (a == 0)
  {
  if (s[i] < t[i]) a=-1;
  if (s[i] > t[i]) a=1;
  if (s[i] == '\0' || t[i] == '\0')
    break;
  i++;
  }
printf("%d\n",a);

a=strcmp(s,t);
printf("%d\n",a);
}
