
	/* Demonstrate some common uses for preprocessing (pg 199) */


	/* Define a macro for a complex operation */
#define KAZAM(x) (((x)*3/4)-2)/5)


	/* Define a constant that may need to be changed later */
#define MAX_LINES 20


	/* Define keyword(s) for system independence */
#define four_bytes int 		/* use on 32-bit machines */
#define four_bytes long int	/* use on 16-bit machines */
#define four_bytes short int	/* use on 64-bit machines */

main()
{
four_bytes x,y,a;

x=7;
}

