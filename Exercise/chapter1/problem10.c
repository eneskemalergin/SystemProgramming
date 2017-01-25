
	/* This is an exercise for debugging. (pg 43) */

#include <stdio.h>

int main()
{
  int n[5] = {0,0,0,0,0};         // Initialize integer array with zeros
  int s,i,j,w;                    // Initialize s, i, j, and w as integer

  for (i=0; i<5; i++)             // Loop 5 times
    {
    printf("Enter any integer: ");
    scanf("%d",&(n[i]));          // Get an integer from user and store it in n
    s=0;                          // Initialize s with 0, use for smallest index
    for (j=1; j<=i; j++)          // Loop i times in each upper loop
    {
      if (n[j] < n[s])            // if jth value is smaller than s
      {
        s=j;                      // rewrite s with j
      }
      /* swap smallest with current */
      w=n[i];
      n[i]=n[s];
      n[s]=w;
      }

    /* swap smallest with current */
    w=n[i];
    n[i]=n[s];
    n[s]=w;

    // printf("%d\n", n[i]);          // Print user's number
    }
  for (i=0; i<5; i++)                 // Loop through the array
    printf("\n%d\n",n[i]);            // and print
}
