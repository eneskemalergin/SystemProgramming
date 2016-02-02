
	/* Code for problem 1 (pgs 204-205) */
	/* Compiling as "gcc -o coin1 coin1.c", what error do you expect? */

#include <stdio.h>

char * Flip_A_Coin(int x)
{
if (x%2 == 0)
  return("heads");
else
  return("tails");
}

