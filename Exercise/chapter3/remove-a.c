
	/* Remove all a's from a string -- easier to code from scratch
	** than to look for a string library solution (pg 91) */

#include <stdio.h>
#include <string.h>

main()
{
int i,j;
char s[6];

s[0]='a'; s[1]='b'; s[2]='a'; s[3]='c'; s[4]=0;
i=0; j=0;
while (s[i] != 0)
  {
  if (s[i] != 'a')
    {
    s[j]=s[i];
    j++;
    }
  i++;
  }
s[j]=0;
printf("%s\n",s);
}
