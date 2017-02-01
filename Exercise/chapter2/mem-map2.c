
	/* Draw the memory map for this code (pg 65) */

#include <stdio.h>

int main()
{
  char a;       // Initialize a as char variable
  int b;        // Initialize b as int variable
  float c;      // Initialize c as float variable
  double d;     // Initialize d as double variable

  a = 7;        // Store 7 in a
  b = -13;      // Store -13 in b
  c = 0.1;      // Store 0.1 in c
  d = 42.5;     // Store 42.5 in d
}

/* Memory Map:

Char occupies 1 byte
Int occupies 4 byte
Float occupies 4 byte
Double occupies 8 byte

Label Address   Value
  a     400       7
  b   401–404    -13
  c   405–408    0.1
  d   409–416    42.5
*/
