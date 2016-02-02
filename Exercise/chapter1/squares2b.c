
	/* This program tries to identify the largest integer whose
	** square is less than the given input number. It works. (pg 34) */

#include <stdio.h>

main()
{
int i,number;

printf("Enter a number: ");
scanf("%d",&number);
i=1;
while (i*i <= number)
  i=i+1;
i--;
printf("%d is the largest square within %d\n",i*i,number);
}
