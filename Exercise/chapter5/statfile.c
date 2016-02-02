
	/* Demonstrate stat(). (pgs 156-158) */

#include <stdio.h>
#include <sys/stat.h> /* needed for stat() function */

int main(int argc, char *argv[])
{
struct stat fileinfo; /* returned info about file */

int i;
if (argc != 2)
  {
  printf("Usage: statfile filename\n");
  exit(0);
  }
i=stat(argv[1],&fileinfo);
if (i == -1)
  {
  printf("Unable to stat %s\n",argv[1]);
  exit(0);
  }
printf("size: %d\n",fileinfo.st_size);
printf("permissions: %d\n",fileinfo.st_mode);
printf("last modified: %d\n",fileinfo.st_mtime);
}

