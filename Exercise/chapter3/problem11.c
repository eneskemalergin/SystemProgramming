
	/* Code for problem 11 (pg 97) */

#include <stdio.h>

main()
{
char     x[3][8];
int      j,length;
float    number;
double   avg;

for (j=0; j<3; j++)
  if (j == 0)
    {
    printf("Enter input string: ");
    scanf("%s",x[0]);
    length=strlen(x[0]);
    }
  else if (j == 1)
    {
    x[0][0]='9'; x[1][0]='7'; x[2][0]='5';
    number=(float)(x[0][0]+x[2][0]);
    }
  else
    avg=(double)(x[0][0]+x[1][0])/2.0;
}
