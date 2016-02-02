
	/* Demonstrate compiling and linking as separate steps during
	** program building (pgs 172-174) */

#include <stdio.h>

int SquareRoot(int n)

{
if (n == 4)
  return(2);
else
  {
  printf("I do not know how to compute the square root of %d\n",n);
  return(-1);
  }
}
