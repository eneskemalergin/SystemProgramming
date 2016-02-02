
	/* Demonstrate #define preprocessing directive (pg 177) */

#define PI	3.14
#define SQRT2	1.7

int main(int argc, char *argv[])

{
printf("PI = %lf\n",PI);
printf("PI = %lf and the square root of 2 = %lf\n",PI,SQRT2);
}
