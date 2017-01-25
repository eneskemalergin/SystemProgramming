
	/* A review of conditionals and blocks in C.  (pg 39) */

#include <stdio.h>

int main()
{
int i,x;                  // Initializing i and x variable as an integer

x=0;                      // Set 0 value into x
for (i=0; i<5; i++)       // Loop from 0 to 4 incremented by 1
{
  if (i%2 == 0 || i == 1) // when i is even or 1
    x=x+i;                // Increment x by 1
  else                    // Otherwise
    x=x-i;                // Decrease x by 1
  printf("%d\n",x);       // Print value of x 
  }
}
