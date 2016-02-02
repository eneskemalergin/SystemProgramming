
	/* Code for problem 9 (pg 97) */

#include <stdio.h>

main()
{
double d[4][3];
int i,j;

for (i=0; i<4; i++)
  for (j=0; j<3; j++)
    if (j == 0)
      d[i][j]=(double)i /10.0;
    else
      d[i][j]=d[i][j-1]+(double)i*2.0;
printf("%lf\n",d[3][2]);
}
