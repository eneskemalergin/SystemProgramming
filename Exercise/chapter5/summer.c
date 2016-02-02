
	/* Used to demonstrate piping at the shell (redirecting the stdin
	** and stdout streams) (pg 146-148) */

#include <stdio.h>

main()
{
int x,s;
s=0;

while (1)
  {
  printf("#? ");
  scanf("%d",&x);
  if (x == 0)
    break;
  s=s+x;
  printf(" sum=%d\n",s);
  }
}

