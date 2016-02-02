
	/* This is an exercise for debugging. (pg 43) */

#include <stdio.h>

int main()
{
int n[5] = {0,0,0,0,0};
int s,i,j,w;

for (i=0; i<5; i++)
  {
  printf("Enter any integer: ");
  scanf("%d",&(n[i]));
  s=0; /* find index of smallest */
  for (j=1; j<=i; j++)
  {
    if (n[j] < n[s]){
      s=j;
    }
    w=n[i]; /* swap smallest with current */
    n[i]=n[s];
    n[s]=w;
    }

  w=n[i]; /* swap smallest with current */
  n[i]=n[s];
  n[s]=w;
  printf("%d\n", n[i]);
  }
for (i=0; i<5; i++)
  printf("\n%d\n",n[i]);
}
