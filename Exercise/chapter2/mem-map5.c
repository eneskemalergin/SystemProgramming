
	/* Draw the memory map for this code.  It can emphasize an
	** unitialized variable (pgs 67-68) */

#include <stdio.h>

main()
{
int i,sum;

printf("%d\n",sum);
for (i=1; i<=10; i++)
if (i%2 == 0)
  sum=sum+i;
printf("%d\n",sum);
}
