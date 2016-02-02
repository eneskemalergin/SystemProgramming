
	/* Concatenate one string to a second string (pgs 87-88) */

#include <stdio.h>
#include <string.h>

main()
{
int i,j;
char s[8],t[4];

s[0]='S'; s[1]='u'; s[2]='\0';
t[0]='s'; t[1]='a'; t[2]='n'; t[3]='\0';
i=strlen(s);
j=0;
while (t[j] != '\0')
  {
  s[i+j]=t[j];
  j++;
  }
s[i+j]='\0';
printf("%s\n",s);

s[0]='S'; s[1]='u'; s[2]='\0';
t[0]='s'; t[1]='a'; t[2]='n'; t[3]='\0';
strcat(s,t);
printf("%s\n",s);
}
