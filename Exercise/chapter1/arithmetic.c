
	/* A review of the basic arithmetic operators in C.  (pg 37) */

#include <stdio.h>

int main()
{
int x,y; // Initialize x and y variables as integer
int r1,r2,r3,r4,r5; //initialize r1, r2, r3, r4, and r5 variables as integer

x = 4; // Store value 4 in variable x
y = 7; // Store value 7 in variable x
r1 = x + y; // Calculate x + y and store result in r1
r2 = x - y; // Calculate x - y and store result in r2
r3 = x / y; // Calculate x / y and store result in r3
r4 = x * y; // Calculate x * y and store result in r4

// Print r1, r2, r3, and r4 respectively with one space between
printf("%d %d %d %d\n",r1,r2,r3,r4);

r3++; // Post-incrementation
r4--; // Post-decrementation
r5=r4%r1; // Calculate remainder from r4/r1 and store result in r5
printf("%d %d %d\n",r3,r4,r5); // Print r3, r4, r5 values respectively
}
