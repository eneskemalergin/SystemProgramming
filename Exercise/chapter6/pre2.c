
	/* Demonstrate #include preprocessing directive (pg 179) */

#define PI	3.14
#define SQRT2	1.7

#include "globals.h"

int main(int argc, char *argv[])

{
printf("PI = %lf\n",PI);
printf("PI = %lf and the square root of 2 = %lf\n",PI,SQRT2);
x=2;
printf("x=%d y=%lf\n",x,y);
}
