
	/* A text editor can identify matching braces, show the
	** current line number, and jump the cursor to a given
	** line number, among other things. (pgs 12-13) */

#include <stdio.h>

int main()
{
  int	i,sum;                    // Initialize i and sum as integer variables

  sum=0;                        // Store value 0 in sum variable
  for (i=0; i<10; i++){         // Loop 10 times


    if (i < 5)                  // If i is smaller than 5
      sum=sum+i;                // Increment sum by i
    else                        // Otherwise
      sum=sum+((i-3)/2+(i/3));  // Increment sum by ((i-3)/2+(i/3))
    }
    printf("sum=%d\n",sum);     // Print the value of sum
}
