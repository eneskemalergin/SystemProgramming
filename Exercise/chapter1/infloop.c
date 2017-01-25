
	/* This program goes into an infinite loop.  It can be paused
	** mid-execution in a debugger to see what is happening. (pg 25) */

#include <stdio.h>

// Why this code is going into infinite loop

// Before x reaches to 10 because of incrementation in for loop definition
//  y gets bigger than 10 and in line 23, conditions turns true and x starts
//  decreasing, bam infinite loop



int main()
{
  int x,y;              // Initialize x and y as integers

  y=0;                  // Set value 0 to y
  for (x=0; x<10; x++)  // Loop 10 times, from 0 to 10 x incremented by 1
  {
    y=y+x;              // Increment y by x
    if (y > 10)         // When y is bigger than 10
      x--;                // Decrement x by 1
    }
}
