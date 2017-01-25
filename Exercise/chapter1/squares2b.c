
	/* This program tries to identify the largest integer whose
	** square is less than the given input number. It works. (pg 34) */

#include <stdio.h>

int main()
{
  int i,number;                 // Initialize i and number as integer variable

  printf("Enter a number: "); // Prompt message
  scanf("%d",&number);        // Prompt user to get a integer number and store it in number

  i=1;                        // Initilize y variable as integer with value 1
  while (i*i <= number)       // Loop until square of i is bigger than number
    i=i+1;                    // Increment i by 1

  i--;                        // Decrement i by 1 after loop is done
  printf("%d is the largest square within %d\n",i*i,number); 
}
