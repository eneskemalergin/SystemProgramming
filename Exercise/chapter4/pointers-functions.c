
	/*
	** Demonstration of returning value from function call via pointer.
	** (pgs 108-109)
	*/

#include <stdio.h>

int division(int numerator, int denominator, int *dividend, int *remainder)

{
printf("address stored in dividend: %u\n",dividend);
printf("address stored in remainder: %u\n",remainder);
if (denominator < 1)
  return(0);
*dividend=numerator/denominator;
*remainder=numerator%denominator;
numerator=7;
}


int main(int argc, char *argv[])

{
int	x,y,d,r;

x=9;
y=2;
printf("address of d: %u\n",&d);
printf("address of r: %u\n",&r);
division(x,y,&d,&r);
printf("%d/%d = %d with %d remainder\n",x,y,d,r);
printf("x=%d\n",x);
}
