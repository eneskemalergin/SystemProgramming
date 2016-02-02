
	/* Demonstrates several uses for comments. (pgs 196-197) */

	/*
	** This program prompts the user for a number,
	** and then determines if the number is a sum
	** of the squares of two unique integers.
	*/

#include <stdio.h>

main()
{
int i,j; 	/* used to test all pairs of squares */
int number;

printf("Enter a number: ");
scanf("%d",&number);
i=1;
while (i*i <= number)	/* i = 1 ... sqrt(number) */
  {
  j=1;
  while (j < i)		/* j = 1 ... i-1 */
    {
    if (i*i + j*j == number)
      printf("Found: %d + %d\n",i*i,j*j);
    j++;
    }
  i=i+1;
  }
}

