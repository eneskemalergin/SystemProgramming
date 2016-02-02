
	/* This program finds if a number is a sum of squares. (pg 34) */

#include <stdio.h>

int main()
{
int i,j,number;

printf("Enter a number: ");
scanf("%d",&number);
i=1;
while (i*i <= number)
  {
  j=1;
  while (j < i)
    {
    if (i*i + j*j == number)
      printf("Found: %d + %d\n",i*i,j*j);
    j++;
    }
  i=i+1;
  }
}
