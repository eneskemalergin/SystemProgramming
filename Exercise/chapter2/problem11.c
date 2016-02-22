
	/* Code for problem #11 in chapter 2 (pg 70) */

#include <stdio.h>

int main()
{
char i;
double d;
int t;

t=0;
for (i='z'; i>='w'; i--)
  for (d=1.0; d<=1.5; d+=0.1)
    if (d-1.3 > 0)
      t++;
printf("%d\n",t);
}

// Output
// 8
