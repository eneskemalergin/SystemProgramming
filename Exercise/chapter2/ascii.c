
	/* This program shows the dual interpretations of char and
	** unsigned char data types. (pg 54) */

#include <stdio.h>

int main()
{
  char a;                         // Initialize a char type variable
  unsigned char b;                // Initialize a char type variable

  a='A';                          // Store character 'A' in a
  b='B';                          // Store character 'B' in b
  printf("%c %c %d %d\n",a,b,a,b);// Showing variable a and b  in both character and ASCII value format
  a=183;                          // Storing integer value in a > It's signed char so it will be represented with negative
  b=255;                          // Storing integer value in b
  printf("%d %d\n",a,b);          // Showing the a and b in integer format
  }
