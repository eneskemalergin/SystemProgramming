
	/* This program tries to identify the largest integer whose
	** square is less than the given input number. It doesn't quite
	** work, and needs fixing before proceeding to the next part
	** of the programming problem. (pg 32) */

#include <stdio.h>

int main()
{
  int i;                        // Initialize i vyariable as integer
  int number;                   // Initialize number variable as integers

  printf("Enter a number: ");   // Prompt Message
  scanf("%d",&number);          // Prompt a number from user and store it in numbers

  int y = 1;                    // Initialize y with value 1 as integer
  // while (y < number)     ->  Changed because it wasn't checking the last number
  while (y <= number){          // Loop while number is bigger than
    i = y*y;                    // Assign square to i
    y++;                        // Increment y by 1
  }
  printf("%d is the largest square within %d\n" ,i ,number);
}
