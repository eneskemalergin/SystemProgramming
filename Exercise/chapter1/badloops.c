
	/* This program is supposed to find sequences of repeating letters.
	** On sequences of 2 letters it works fine; on 3 or more letters it
	** prints redundant lines of output.
	**
	** The debugger can be used to step through a loop, one line
	** at a time, to observe what the code is doing. (pg 29) */

// Fixed by Enes Kemal Ergin

#include <stdio.h>

int main() // int  added
{
char word[80];
int i,j;

printf("Enter any word: ");
scanf("%s",word);
i=0;
while (word[i] != '\0')
  {
  if (word[i] == word[i+1])
    {
    j=1;
    while (word[i] == word[i+j]){
      j++;
    }
    printf("%d consecutive %c\n",j,word[i]);
    }
  i++;
  }
}
