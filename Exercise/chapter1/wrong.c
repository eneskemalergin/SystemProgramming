
	/* This program works partially, but then displays the wrong
	** values after some data is input.  A debugger can be used
	** to break at the problem area and step through the code line
	** by line to find the problem. (pgs 26-27) */

#include <stdio.h>

int main()
{
int choice;                       // Initialize choice variable as integer
float ppg,rpg;                    // Initialize ppg and rpg variables as integer

ppg=rpg=0.0;                      // Store 0.0 in ppg and rpg variable
choice=0;                         // Store 9 in choice variable
do                                // Start loop with do while syntax
  {
  printf("(1) Enter points per game\n");
  printf("(2) Enter rebounds per game\n");
  printf("(3) Quit\n");
  scanf("%d",&choice);            // Prompt user for number and store it in choice
  if (choice == 1 || choice == 2) // When choice is 1 or 2
    {
    printf("Amount: ");           //
    if (choice == 1)              // When choice is 1
      scanf("%f",&ppg);           // Get value from user for ppg
    else if (choice == 2)         // When choice is 2
      scanf("%f",&rpg);           // Get value from user for rpg
    printf("Points=%f Rebounds=%f\n",ppg,rpg);
    }
  }
while (choice != 3);              // Keep looping until choice is 3
}
