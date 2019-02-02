#include "parser.h"
#include "lex.h"
#include "name.h"
#include <stdio.h>

FILE *codefile;
int main ()
{
	FILE *codefile = fopen("code.txt",'r');
	FILE *assemblyfile = fopen ("code.asm",'w');
	fprintf(assemblyfile,"ORG 8000H\n");
    if ( !match(EOI) )
    {
	   statements();
    }
	fprintf(assemblyfile, "END\n");
	fclose(codefile);
	fclose(assemblyfile);
}
