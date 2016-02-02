
	/* This program tries to identify the largest integer whose
	** square is less than the given input number. It doesn't quite
	** work, and needs fixing before proceeding to the next part
	** of the programming problem. (pg 32) */

#include <stdio.h>

int main()
{
  int i;
  int number;

  printf("Enter a number: ");
  scanf("%d",&number);

  int y = 1;
  while (y < number){
    i = y*y;
    y++;
  }
  printf("%d is the largest square within %d\n" ,i ,number);
}
