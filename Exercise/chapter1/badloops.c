
	/* This program is supposed to find sequences of repeating letters.
	** On sequences of 2 letters it works fine; on 3 or more letters it
	** prints redundant lines of output.
	**
	** The debugger can be used to step through a loop, one line
	** at a time, to observe what the code is doing. (pg 29) */

// Fixed by Enes Kemal Ergin

#include <stdio.h>

// main() -> int main()
int main()
{
char word[80];                   // Create a character variable with 80 space available.
int i,j;                         // Create i and j variable as integer

printf("Enter any word: ");      // Prints the user prompt message
scanf("%s",word);                // Prompts the user to put a word
i=0;                             // Initialize loop counter
while (word[i] != '\0')          // Run over the character sequence until end character ('\0')
  {
  if (word[i] == word[i+1])      // If there are two consecutive characters
  {
    j=0;                         // Start
    while (word[i] == word[i+j]) //
    {
      j++;
    }
    printf("%d consecutive %c\n",j,word[i]);
    }
  i++;
  }
}
