
	/* Demonstrate the stdin and stdout streams (pg 142) */

#include <stdio.h>

main()
{
char s[80];
int x=42;

scanf("%s",s);		/* scanf() is "hardwired" to the stdin stream */
fscanf(stdin,"%s",s);

printf("%d is a nice number\n",x);	/* printf() goes to stdout */
fprintf(stdout,"%d is a nice number\n",x);
}
