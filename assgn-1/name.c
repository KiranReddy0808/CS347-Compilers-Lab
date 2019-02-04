#include "lex.h"
#include "name.h"
#include <stdio.h>
#include <stdlib.h>
#include <error.h>


char *Names[] = { "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7" };	 /* Temporary variables used by the compiler */
char **Namep  = Names;  /* Helps to determine the availability of temporary variables */

int numIfThen=0;	/* counts number of 'if..then' to name the labels */
int numWhile=0;		/* counts number of 'while...do' to name the labels */
int numComparisions=0;	/* counts number of comparisions(=,<,>) to name the labels */
   
char  *newname()  /* takes requests for new temporary variable */ 
{   
	if (Namep >= &Names[sizeof(Names)/sizeof(*Names)]){
		fprintf( stderr, "%d: Expression too complex\n", yylineno );   
		exit(1);   
	}
	return(*Namep++);
}   
   
void freename(char *s)	/* frees a used temporary variable */
{   
	if (Namep > Names){
		*--Namep = s;   
	}else{ 
		fprintf(stderr, "%d: (Internal error) Name stack underflow\n", yylineno );
	}
}   

int num_COMPARISIONS(){
	return numComparisions++ ;
}

int num_IFTHEN(){
	return numIfThen++ ;
}

int num_WHILE(){
	return numWhile++ ;
}