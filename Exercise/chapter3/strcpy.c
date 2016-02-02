
	/* Copying a string (pgs 86-87) */

#include <stdio.h>
#include <string.h>

main()
{
int i;
char s[4],t[4];

s[0]='S'; s[1]='u'; s[2]='e'; s[3]='\0';
i=0;
while (s[i] != '\0')
  {
  t[i]=s[i];
  i++;
  }
t[i]='\0';
printf("%s\n",t);

strcpy(t,s);
printf("%s\n",t);
}
