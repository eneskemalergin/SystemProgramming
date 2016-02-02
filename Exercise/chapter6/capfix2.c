
	/* Reads in a file of names and fixes capitalization.  This version
	** uses functions to organize the code. (pgs 187-188) */

#include <stdio.h>
#include <string.h>

int ReadData(FILE *fpt,
	     char first[20][30],
	     char last[20][30])
{
int total;

total=0;
while (1)
  {
  if (fscanf(fpt,"%s %s",last[total],first[total]) != 2)
    break;
  total++;
  }
return(total);
}

void CapFix(char word[30])
{
int i;

if (word[0] >= 'a' && word[0] <= 'z')
  word[0]=word[0]-'a'+'A';
for (i=1; i<strlen(word); i++)
  if (word[i] >= 'A' && word[i] <= 'Z')
    word[i]=word[i]-'A'+'a';
}


int main(int argc, char *argv[])
{
FILE *fpt;
char first[20][30],last[20][30];
int i,j,total;

if (argc != 2)
  {
  printf("Usage: capfix [filename]\n");
  exit(0);
  }
if ((fpt=fopen(argv[1],"r")) == NULL)
  {
  printf("Unable to open %s for reading\n",argv[1]);
  exit(0);
  }

total=ReadData(fpt,first,last);

for (i=0; i<total; i++)
  CapFix(first[i]);
for (i=0; i<total; i++)
  CapFix(last[i]);

for (i=0; i<total; i++)
  printf("%s %s\n",first[i],last[i]);
}

