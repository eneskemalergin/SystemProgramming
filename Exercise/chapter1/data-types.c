
	/* A review of the basic data types in C.  (pg 36) */

#include <stdio.h>

int main()
{
int	x,y;
char	a;
float	f,e;
double	d;

x=4;
y=7;
a='H';
f=-3.4;
d=54.123456789;
e=54.123456789;

printf("%d %c %f %lf\n",x,a,e,d);
printf("%d %c %.9f %.9lf\n",x,a,e,d);
}

