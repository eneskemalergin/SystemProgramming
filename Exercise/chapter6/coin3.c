
	/* Code for problem 3 (pgs 205-206) */
	/* Compiling as "gcc -c coin3.c", what error do you expect? */

#define HEADS "heads"
#define TAILS "tails"

char * Flip_A_Coin(int x)
{
if (x == heads)
  return(HEADS);
else
  return(TAILS);
}

