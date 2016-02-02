
	/* Print out the command line arguments - they are an array of
	** strings (pgs 93-94) */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
int i,j;

for (i=0; i<argc; i++)
  {
  j=0;
  while (argv[i][j] != '\0')
    {
    printf("%c",argv[i][j]);
    j++;
    }
  printf("\n");
  }

for (i=0; i<argc; i++)
  printf("%s\n",argv[i]);
}
