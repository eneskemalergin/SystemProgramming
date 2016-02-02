
	/*
	** This program shows how a chunk of memory can be accessed
	** as an array, or using a pointer.  In the first case, it
	** shows how array indices move up and down the memory.
	** In the second case, it shows how pointer arithmetic does
	** the exact same thing.  (pgs 111-112)
	*/

#include <stdio.h>

int main(int argc, char *argv[])

{
double	array[10];
double	*d_ptr;
double	value;
int	i,offset;


for (i=0; i<10; i++)
  array[i]=(double)i+10.0;	/* access memory using array index */

d_ptr=&(array[0]);		/* access memory using pointer */

while (1)
  {
  printf("Address(hex)\tAddress(base10)\tValue\n");
  for (i=0; i<10; i++)
    printf("%p\t%u\t%lf\n",&(array[i]),&(array[i]),array[i]);
  printf("Enter offset value (0 0 to quit): ");
  scanf("%d %lf",&offset,&value);
  if (offset == 0  &&  value == 0.0)
    break;			/* break out of loop */
  if (offset < 0  ||  offset > 9)
    {
    printf("Offset out of bounds\n");
    continue;			/* go back to start of loop */
    }
  array[offset]=value;		/* using array syntax */
  *(d_ptr+offset)=value;	/* using pointer syntax */
  *(array+offset)=value;	/* using mixed syntax */
  }
}
