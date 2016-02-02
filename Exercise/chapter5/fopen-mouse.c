
	/* Demonstrate file I/O concepts on mouse device (pgs 162-163) */
	/* NOTE: Must be root to run this example, or have permissions to
	** access /dev/psaux */

#include <stdio.h>

main()
{
FILE *fpt;
int c,buf[4];

fpt=fopen("/dev/psaux","r");
while (1)
  {
  c=fread(buf,4,1,fpt);
  printf("Read %d bytes: %d\n",c,buf[0]);
  }
fclose(fpt);
}

