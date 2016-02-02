
	/* Code for problem 9 (pgs 208-209) */

#include <stdio.h>

main()
{
int i,s;
int a[6];
typedef int * stair;
stair b;

a[0]=83;
a[1]=13;
b=&(a[2]);
s=0;
for (i=2; i<5; i++)
  {
  *b=a[i-2]%a[i-1];
  s+=(*b);
  b++;
  }
printf("%d\n",s);
}

