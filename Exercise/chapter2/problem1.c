
	/* Code for problem 1*/
	/* Show the total number of bits used, and all the bit values, for the following variables:*/

#include <stdio.h>

int main()
{
  char c = 35;
  char d = 'G';
  int x = -42;
  float f = 17.25;
  int i = 1099563008;
  double a = 17.25;
}

/* Answer
	c - 8 bits  | 0010 0011
	d - 8 bits  | 0100 0111
	x - 32 bits | 1000 0000 0000 0000 0000 0000 0000 0000
	f - 32 bits | 0000 0000 0000 0000 0000 0000 0000 0000
	i - 32 bits | 0000 0000 0000 0000 0000 0000 0000 0000
	a - 64 bits | 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
*/
