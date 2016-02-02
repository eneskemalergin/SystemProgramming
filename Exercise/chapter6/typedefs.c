
	/* Demonstrate typedefs (pg 200) */


	/* The basic pattern is:
	** typedef SomeExistingType MyNewNameForIt; */

typedef int frog;

main()
{
int a;
frog b;

a=4;
b=3;
}

	/* Often used to make an alias for a "struct something" */

struct TemplateName {
		    int field1;
		    float field2;
		    } ;
typedef struct TemplateName NewStructType;

struct TemplateName s1;
NewStructType s2;


	/* The steps above are often combined. */

typedef struct TemplateName {
			    int field1;
			    float field2;
			    } NewStructType;


	/* typedefs can also be used for system portability */

typedef int Int32;		/* 4 byte variable */
typedef short int Int16;	/* 2 byte variable */

