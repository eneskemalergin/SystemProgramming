
	/* Draw the memory map for this code.  It can emphasize an
	** unitialized variable (pgs 67-68) */

#include <stdio.h>

int main()
{
  int i,sum;            // Initialize i and sum as integer variable

  printf("%d\n",sum);   // Print the random value given in creation of sum variable
  for (i=1; i<=10; i++)
  if (i%2 == 0)
    sum=sum+i;
  printf("%d\n",sum);   // The Sum after adding 30 will be 30 more than the initial sum value
}
