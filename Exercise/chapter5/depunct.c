
	/* An example program to test shell redirection (in class
	** exercise to do this).  Run as depunt < test1.txt > output1.txt
	** to show redirecting stdin and stdout.
	**
	** Also demonstrate "diff" command to compare output1.txt to
	** expected1.txt and output2.txt to expected2.txt.  Use this
	** material to discuss testing, and the creation of test patterns.
	** (pgs 150-153)
	*/

#include <stdio.h>

int main (int argc, char *argv[])

{
char	textin[80],wordout[80];
int	i,j;

if (argc > 1)
  {
  printf("Usage:  depunct\n");
  exit(0);
  }

while (1)
  {
  scanf("%s",textin);
  if (strcmp(textin,".") == 0)
    break;
  strcpy(wordout,textin);
  for (i=0; i<strlen(wordout); i++)
    if (wordout[i] == '.'  ||  wordout[i] == ','  ||
	wordout[i] == '"'  ||  wordout[i] == ';'  ||
	wordout[i] == '!'  ||  wordout[i] == '?'  ||
	wordout[i] == '('  ||  wordout[i] == ')'  ||
	wordout[i] == ':')
      {
      for (j=i; j<strlen(wordout)-1; j++)
        wordout[j]=wordout[j+1];
      wordout[j]='\0';
      }
  printf("%s\n",wordout);
  }
}
