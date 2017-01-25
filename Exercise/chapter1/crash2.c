
	/* This program crashes.  The crash point and reason for crashing
	** can be quickly identified using a debugger.  (pg 23) */

#include <stdio.h>

// Why is the error occurs?

// The segmentation fault occurs, segmentation fault is occurs when
//  user tries to reach a memory location which is forbidden
// In the following code we are trying to reach the 54389th location of array z
// which is not reserved for this application

int main()
{
                        // z[3] is defined as 3 element array with integers values allowed
int x,y,z[3];           // Initialize x, y and z variables as integers


y=54389;                // Storing the value 54389 in y
for (x=10; x>=1; x--)   // Loops from 10 to 0 by decreasing x by 1
  z[y]=y/x;             // Trying to store result of y/x at yth location in z
printf("%d\n",z[0]);    // Print first element of z
}
