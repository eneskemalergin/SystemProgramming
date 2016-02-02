
	/* Demonstrate fseek() and ftell(). (pg 155) */

#include <stdio.h>

int main(int argc,char *argv[])

{
FILE	*fpt;
char	byte;
int	where,move;


if (argc != 2)
  {
  printf("Usage:  fileseek filename\n");
  exit(0);
  }
if ((fpt=fopen(argv[1],"r")) == NULL)
  {
  printf("Unable to open %s for reading\n",argv[1]);
  exit(0);
  }

while (1)
  {
  where=ftell(fpt); 		/* which byte is pointed to by file pointer */
  fread(&byte,1,1,fpt);		/* moves fpt ahead one byte after fread */
  fseek(fpt,-1,SEEK_CUR);	/* back up one byte, so stay at same place */
  printf("Byte %d: %d (%c)\n",where,byte,byte);
  printf("Enter #bytes (positive or negative) to move, or 0 to quit: ");
  scanf("%d",&move);
  if (move == 0)
    break;
  fseek(fpt,move,SEEK_CUR);
  }

fclose(fpt);
}
