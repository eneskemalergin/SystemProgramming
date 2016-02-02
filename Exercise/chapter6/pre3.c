
	/* Demonstrate using preprocessing for debugging (pgs 179-180) */

#define DEBUG	1	/* change to 0 to turn off debugging output */

main()

{
int	x,y,s;

y=1;
s=0;
for (x=0; x<10; x++)
  {
  y=y<<1;
  s=s+y;
#if DEBUG == 1
  printf("When x=%d, y=%d\n",x,y);
#endif
  }
printf("s=%d\n",s);
}

