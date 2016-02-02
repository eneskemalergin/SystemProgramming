
	/* Code for problem 2 (pg 165) */

#include <stdio.h>

main()
{
FILE *fpt;
struct frog {
	    float d;
	    int x;
	    } henry;

henry.d=12.73;
henry.x=81925;
fpt=fopen("out2","w");
fprintf(fpt,"%7.2f %7d\n",henry.d,henry.x);
fwrite(&henry,sizeof(struct frog),1,fpt);
fclose(fpt);
}

