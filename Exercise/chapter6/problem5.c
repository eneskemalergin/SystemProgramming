
	/* Code for problem 5 (pgs 206-207) */
	/* What does this code do?  Organize it. */

#include <stdio.h>

main()
{
int a,b,c,d;

a=0;
while (1) {
printf("%d\n",a);
printf("Input? ");
scanf("%d",&c);
if (c == 0) break;
d=0;
for (b=1; b<=c; b++)
if (c%b == 0) d++;
if (d == 2 || c == 1) a=a+c;
}
}

