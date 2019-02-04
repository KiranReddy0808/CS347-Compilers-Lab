#include "parser.h"
#include "lex.h"
#include "name.h"
#include <stdio.h>
#include <stdlib.h>

extern FILE *codefile, *assemblyfile; /* File pointers for the input file and the output file */

int main ()
{
	codefile = fopen("code.txt","r");	/* Input file */
	assemblyfile = fopen ("assembly.txt","w");	/* Output file*/ 
	if(codefile== NULL || assemblyfile== NULL){	
		fprintf( stderr, "Files not opening\n");
	}
	fprintf(assemblyfile,"ORG 8000H\n");	/* Intialising the assembly code file */
    if (!match(EOI))			
    {
	   statements();	/* Checks for multiple statements in input file */
    }
	fprintf(assemblyfile, "END\n");		/* Ends the assembly code file */
	fclose(codefile);
	fclose(assemblyfile);
}
