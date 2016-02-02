
	/* Demonstrate opendir(), readdir() and closedir(). (pgs 160-161) */

#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
DIR *directory; /* the directory */
struct dirent *entry; /* each entry */

directory=opendir(".");
if (directory == NULL)
  {
  printf("Unable to open directory .\n");
  exit(0);
  }
while (1)
  {
  entry=readdir(directory);
  if (entry == NULL)
    break;
  printf("%s\n",entry->d_name);
  }
closedir(directory);
}
