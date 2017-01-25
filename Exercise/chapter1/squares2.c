
	/* This program tries to identify the largest integer whose
	** square is less than the given input number. It fixes some
	** of the problem from the first version, but still isn't
	** quite right. (pg 33) */

#include <stdio.h>

int main()
{
  int i,number;               // Initialize i and number as integer variable

  printf("Enter a number: "); // Prompt message
  scanf("%d",&number);        // Prompt user to get a integer number and store it in number
  int y = 1;                  // Initilize y variable as integer with value 1
  // while(y < number) ->     It was not going to go throught the last number in number
  while (y <= number){        // Loop untill number is smaller than y
    i = y*y;                  // Store the square of y in i
    y++;                      // Increment y by 1
  }
  printf("%d is the largest square within %d\n",i,number);
}
