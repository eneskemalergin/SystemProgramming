
	/* This is the code for problem #17 in chapter 2 (pg 72) */

#include <stdio.h>

main()
{
int i;
double d;
char s[10];

s[0]='f'; s[1]='r'; s[2]='o'; s[3]='g';
d=0.0;
for (i=0; i<4; i++)
d=d+(double)(s[i]-'a');
}

