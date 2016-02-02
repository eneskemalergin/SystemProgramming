
	/* Code for problem 2 (pg 205) */
	/* Compiling as "gcc -o coin2 coin2.c", what error might you expect? */

#define HEADS 0

#include "some_library.h"

char * Flip_A_Coin(int x)
{
if (x%2 == HEADS)
  return("heads");
else
  return("tails");
}

main()
{
printf("%s\n",Flip_A_Coin(1));
}

