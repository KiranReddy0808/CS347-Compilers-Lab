#include "lex.h"
#include <stdio.h>
#include <stdlib.h>
#include <error.h>


char *Names[] = { "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7" };   
char **Namep  = Names;  

int numIfThen=0;
int numWhile=0;
int numComparisions=0;
   
char  *newname()   
{   
	if (Namep >= &Names[sizeof(Names)/sizeof(*Names)])   
	{
		fprintf( stderr, "%d: Expression too complex\n", yylineno );   
		exit(1);   
	}
	return(*Namep++);
}   
   
freename(char *s)
{   
	if (Namep > Names){
		*--Namep = s;   
	}
	else{ 
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