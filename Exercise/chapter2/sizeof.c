
	/* This program demonstrates the sizeof() operator. (pg 57) */

#include <stdio.h>

int main()
{
  int i;
  char c;
  double d;

  printf("%d %d %d %d\n",sizeof(i),sizeof(c),sizeof(d),sizeof(float));
}
