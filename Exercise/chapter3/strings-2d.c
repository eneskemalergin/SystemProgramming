
	/* How does an array of strings fit in memory?
	** Draw the memory map. (pg 82) */

#include <stdio.h>

main()
{
char n[2][4];
n[0][0]='T'; n[0][1]='o'; n[0][2]='m'; n[0][3]=0;
n[1][0]='S'; n[1][1]='u'; n[1][2]='e'; n[1][3]=0;

printf("%s %s\n",n[0],n[1]);
}
