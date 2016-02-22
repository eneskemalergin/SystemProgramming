/* Write a memory map for the following code. Show all values at the end of execution of the program.*/

#include <stdio.h>

int main()
{
int i;
double d;
char s[10];

s[0]='f'; s[1]='r'; s[2]='o'; s[3]='g';
d=0.0;
for (i=0; i<4; i++)
	d=d+(double)(s[i]-'a');
printf("%lf\n", d ); // To find d at the end.
}

/* Memory Map
"a" = 97
"f" = 102
"r" = 114
"o" = 111
"g" = 103

labels 		| address 	 | bit represent | Value
------   		------      -------------   -----
i      		| 401-403 |  0000 0000 0000 0011    										|  3
d      		| 404-411 |  0000 0000 0000 0000 0000 0000 010 1010    | 42
s[0]	 	  | 412	    |  0110 0110 																	|  f
s[1]	 		| 413		  |  0111 0010																	|  r
s[2]   		| 414     |	 0110 1111																	|  o
s[3]   		| 415			|  0110 0111																	|  g
s[4]-s[9] | 416-421 |  0000 0000 																	|






*/
