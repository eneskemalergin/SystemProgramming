
	/* A review of the basic data types in C.  (pg 36) */

#include <stdio.h>

int main()
{
int	x,y;                              // Initialize x and y variables as integers
char	a;                              // Initialize a variable as character
float	f,e;                            // Initialize f and e variable as floats
double	d;                            // Initialize d variable as double type

x=4;                                  // Store value 4 in x (int)
y=7;                                  // Store value 7 in y (int)
a='H';                                // Store value 'H' in a (char)
f=-3.4;                               // Store value -3.4 in f (float)
d=54.123456789;                       // Store value  in d as float
e=54.123456789;                       // Store value in e as double

printf("%d %c %f %lf\n",x,a,e,d);     // Print x, a, e, and d
printf("%d %c %.9f %.9lf\n",x,a,e,d); // Print x,a,e, and d with precision
}
