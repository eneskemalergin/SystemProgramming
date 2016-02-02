
	/* This program tries to identify the largest integer whose
	** square is less than the given input number. It fixes some
	** of the problem from the first version, but still isn't
	** quite right. (pg 33) */

#include <stdio.h>

int main()
{
int i,number;

printf("Enter a number: ");
scanf("%d",&number);
int y = 1;
while (y < number){
  i = y*y;
  y++;
}
printf("%d is the largest square within %d\n",i,number);
}
