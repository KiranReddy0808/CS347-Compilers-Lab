#include "parser.h"
#include "lex.h"
#include "name.h"
#include <stdio.h>
#include <stdlib.h>

extern FILE *codefile, *assemblyfile;
int main ()
{
	codefile = fopen("code.txt","r");
	assemblyfile = fopen ("assembly.txt","w");
	if(codefile== NULL || assemblyfile== NULL){
		fprintf( stderr, "Files not opening\n");
	}
	fprintf(assemblyfile,"ORG 8000H\n");
    if (!match(EOI))
    {
	   statements();
    }
	fprintf(assemblyfile, "END\n");
	fclose(codefile);
	fclose(assemblyfile);
}
