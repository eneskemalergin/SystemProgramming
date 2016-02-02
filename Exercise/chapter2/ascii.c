
	/* This program shows the dual interpretations of char and
	** unsigned char data types. (pg 54) */

#include <stdio.h>

int main()
{
char a;
unsigned char b;

a='A';
b='B';
printf("%c %c %d %d\n",a,b,a,b);
a=183;
b=255;
printf("%d %d\n",a,b);
}
