
	/* A review of flow control statements in C.  (pg 40) */

#include <stdio.h>

int main()
{
int i,x;            // Initialize i and x as integers

x=0;                // Store 0 in x for counting in for loop
for (i=0; i<5; i++) // Loop 5 times from 0 to 5 incremented by 1
  {
  if (i%2 == 0)     // if i is even
    continue;       // Continue to next iteration directly
  x=x-i;            // Decrement x by i
  if (i%4 == 0)     // if i is divisible by 4
    break;          // Stop the iteration
  printf("%d\n",x); // Print x
  }
}
