
	/* Draw the memory map for this code.  Showing the bit patterns
	** emphasizes the differences in storage of "6" (pg 66) */

#include <stdio.h>

int main()
{
  char a;       // Initialize a as char variable
  short int b;  // Initialize b as shor int variable
  char c;       // Initialize c as char variable

  a = 6;        // Store 6 in a
  b = 13;       // Store 13 in b
  c = '6';      // Store "6" in c
}


/* Memory Map:
Character 6 and integer 6 has different bit patterns
Short integer occupies 2 byte

Label     Address           Bits        Value/symbol
a           400           0000 0110          6
b         401–402   0000 0000 0000 1101     13
c           403           0011 0110         ’6’

*/
