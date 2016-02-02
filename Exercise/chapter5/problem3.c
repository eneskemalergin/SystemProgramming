
	/* Code for problem 3 (pgs 165-166) */

#include <stdio.h>

main()
{
double testd;
int testi;
FILE *fpt;
struct frog {
	    double *x,y;
	    };
struct frog turtle,*apple,tv[3];

testi=21;
apple=&turtle;
turtle.y=5.2;
fpt=fopen("out3","w");
fwrite(apple,sizeof(struct frog),1,fpt);
fclose(fpt);

apple->x=&testd;

fpt=fopen("out3","r");
fread(&(tv[1]),sizeof(struct frog),1,fpt);
fclose(fpt);

*(turtle.x)=7.3;
(*apple).y=3.6;
turtle.y=1.5;
*(tv[1].x)=6.4;

printf("%lf \n",tv[1].y);
}

