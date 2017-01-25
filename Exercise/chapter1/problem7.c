
	/* This is an exercise for debugging. (pg 42) */

	/* This code has a compile-time error, and at
	** least one run-time error.  */

#include <stdio.h>
#include <math.h>

int main(int argc,char *argv[])
{
int n,i;                              // Initialize n and i as integer variables
// int d2,count, -> Compile time error fixed with forgotten semicolon
int d2, count;                        // Initialize d2 and count as integer variables
double d1;                            // Initialize d1 as double variable

while (1)                             // Always loop 1=True
  {
  printf("Enter a number (0 to quit): ");
  scanf("%d",&n);                     // Get n from prompt
  if (n == 0)                         // If input n is 0
    break;                            // Break the loop
  count=0;                            // Store 0 to count variable as counter
  for (i=0; i<n; i++)                 // Loop until n is reached
    {
    d1=(double)n/(double)i;           // Divide n by i
    // d2 = n/i   // It was trying to store non double value into double holder
    d2=(double)n/(double)i;           // divide n by i again
    if (fabs(d1-(double)d2) < 0.00001)// if absoulute value of d1 - d2 is smaller than value
      count++;                        // Increase the count
    }
  if (count == 2)                     // When count is equal to 2
    printf("%d is prime\n",n);        // Print prime
  else
    printf("%d is not prime\n",n);    // Otherwise don't print
  }
}
