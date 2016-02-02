
	/* This program works partially, but then displays the wrong
	** values after some data is input.  A debugger can be used
	** to break at the problem area and step through the code line
	** by line to find the problem. (pgs 26-27) */

#include <stdio.h>

int main()
{
int choice;
float ppg,rpg;

ppg=rpg=0.0;
choice=0;
do
  {
  printf("(1) Enter points per game\n");
  printf("(2) Enter rebounds per game\n");
  printf("(3) Quit\n");
  scanf("%d",&choice);
  if (choice == 1 || choice == 2)
    {
    printf("Amount: ");
    if (choice == 1)
      scanf("%f",&ppg);
    else if (choice == 2)
      scanf("%f",&rpg);
    printf("Points=%f Rebounds=%f\n",ppg,rpg);
    }
  }
while (choice != 3);
}
