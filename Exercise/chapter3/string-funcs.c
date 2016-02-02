
	/* Demonstrate using several string library functions (pgs 89-90) */

#include <stdio.h>	/* for printf(), scanf() */
#include <string.h>	/* for strlen(), strcmp() */

main()
{
char look[80],test[80];

printf("Look for: ");
scanf("%s",look);
while (1)
  {
  printf("Enter a string (0 to quit): ");
  scanf("%s",test);
  if (strcmp(test,"0") == 0)
    break;
  if (strlen(test) < strlen(look))
    printf("%s is too short for %s\n",test,look);
  else if (strcmp(test,look) == 0)
    printf("Found one!\n");
  else if (strncmp(test,look,3) == 0)
    printf("Started the same...\n");
  else
    printf("Not what we're looking for\n");
  }
}
