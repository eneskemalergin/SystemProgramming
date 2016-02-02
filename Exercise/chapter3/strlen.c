
	/* Computing the length of a string (pg 84) */

#include <stdio.h>
#include <string.h>

main()
{
int length;
char s[6];

s[0]='S'; s[1]='u'; s[2]='e'; s[3]='\0';
length=0;
while (s[length] != '\0')
  length++;
printf("%d\n",length);

length=strlen(s);
printf("%d\n",length);
}
