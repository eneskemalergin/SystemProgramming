
	/* Code for problem 10 (pg 130) */

#include <stdio.h>

main()
{
double testd;
int testi;
struct frog {
	    double *x,y;
	    };
struct frog turtle,*apple,tv[3];

testi=2;
apple=&turtle;
apple->x=&testd;
*(turtle.x)=7.3;
(*apple).y=3.6;
turtle.y=1.5;
for (testi=0; testi<3; testi++)
  tv[testi].x=&(tv[(testi+1)%3].y);
*(tv[1].x)=6.4;
}
