
	/* This program crashes.  The crash point can be found
	** using a debugger. (pgs 21-22). */

#include <stdio.h>

// Why This code is crashes?

// This code crashes because we are trying to divide
//  y value by 9 in the fist iteration

int main()
{
int x,y;              // Initialize x and y variable as integer

y=54389;              // Set 54389 value to y
for (x=10; x>=0; x--) // Loop until 10 becomes 0 , 10 times
  y=y/x;              // Decrement by division of x in each time
printf("%d\n",y);     // Print the y value at the end of the for loop
}
