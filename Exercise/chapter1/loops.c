
	/* A review of the loop types in C. (pg 38) */

#include <stdio.h>

int main()
{
  int i,x;            // Initialize i and x variables as integers

  x=0;                // Store value 0 in x variable

  for (i=0; i<4; i++)  // For loop iterates 4 times
  {
    x=x+i;             // x incremented by i in each iteration
    printf("%d\n",x);  // Print value of x
  }

  while (i<7)         // value i goes from 4 to 7, iterates 3 times
  {
    x=x+i;            // each iterations adds i to x
    i++;              // Increment i
    printf("%d\n",x); // prin
  }

  do
  {
    x=x+i;            // Iterates 3 times including 9 because condition is at down
    i++;              // increment i
    printf("%d\n",x); // Print value of x
  }
  while (i<9);         // Checks the condition for do while loop
}
