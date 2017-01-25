
	/* This program finds if a number is a sum of squares. (pg 34) */

#include <stdio.h>

int main()
{
  int i,j,number;             // Initialize i, j and number as integer variables

  printf("Enter a number: "); // Prompt message
  scanf("%d",&number);        // Prompts user to put an integer and store it in numbers
  i=1;                        // Store value 1 in i
  while (i*i <= number)       // Loop until i square is bigger than number
  {
    j=1;                      // Store value 1 in j
    while (j < i)             // Loop until j is bigger or equal to i
    {
      if (i*i + j*j == number)// When i square and j square is equal to number
        printf("Found: %d + %d\n",i*i,j*j); // Found message printed
      j++;                    // Increment j by 1
    }
    i=i+1;                    // Increment i by 1
  }
}
