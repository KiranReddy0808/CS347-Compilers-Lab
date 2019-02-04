#include "name.h"
#include "lex.h"
#include "name.h"
#include <stdio.h>
#include <error.h>

void statements()
{
    /* 
        statements -> statements statement 
                    | statement
    */
    while (!match(EOI)){
        statement();
    }
}

void statement()
{
    /*
        statement -> ID := expression;
                    | IF expression THEN statement
                    | WHILE expression DO statement
                    | BEGIN statements END
                    | expression;
    */
     
    char *t;
    
    /* CONSIDERING THAT 'legal_lookahead' FUNCTION CHECKS IF THERE EXISTS THAT TOKEN ANY WHERE AHEAD else u gotto change the order of that func and 'advance' in many places*/
    
    if (match(NUM_OR_ID)){

        char variable[yyleng+1];
        fgets(variable,yyleng,codefile);
        variable[yyleng]='\0';
        advance();
        if(!legal_lookahead(EQU,0)){
            fprintf(stderr, "%d: Error in assignment operation\n", yylineno);
            if (match(SEMI)){
                advance();
            }else{
                    fprintf( stderr, "%d: Inserting missing semicolon\n", yylineno );
                    return;
                }
        }else{
            advance();
            t=expression();
            if(!strcmp(t,"t0")){
                fprintf(assemblyfile, "STA _%s\n", variable);
            }else{
                fprintf(assemblyfile,"PUSH A\nMOV A,%c\nSTA _%s\nPOP A\n", Reg[t[1]-'0'],variable);
            }
        }
    }
    else if(match(IF)){
        if (!legal_lookahead(THEN, 0)){
            fprintf(stderr, "%d: Missing 'then'\n", yylineno);
            if (match(SEMI)){
                advance();
            }else{
                    fprintf( stderr, "%d: Inserting missing semicolon\n", yylineno );
                    return;
                }
        }else{
            advance();
            t=expression();
            int ifcounter = num_IFTHEN();
            fprintf(assemblyfile, "CMP %c 0\n", Reg[t[1]-'0']);
            fprintf(assemblyfile,"JZ IFTHEN%d\nIFTHEN%d:\n", ifcounter, ifcounter) ;
            freename(t);
            advance();
            if(match(THEN)){
                advance();
                statement();
                return;
            }
        }        
    }
    else if(match(WHILE)){
        /* STILL HAVE TO CLARIFY THE REQUIREMENT OF TWO LABELS IN ONE WHILE...DO */
        if (!legal_lookahead(DO,0)){
            fprintf(stderr, "%d: Missing 'do'\n",yylineno);
            if (match(SEMI)){
                advance();
            }else{
                    fprintf( stderr, "%d: Inserting missing semicolon\n", yylineno );
                    return;
                }
        }else{
            advance();
            t=expression();
            int whilecounter = num_WHILE();
            fprintf(assemblyfile, "WHILELOOP%d:\n", whilecounter);
            fprintf(assemblyfile, "CMP %c 0\n",Reg[t[1]-'0']);
            fprintf(assemblyfile, "JZ WHILELOOP%d\n", whilecounter) ;
            freename(t);
            advance();
            if (match(DO)){
                advance();
                statement();
                int whilecounter2 = num_WHILE();
                fprintf(assemblyfile, "JMP WHILELOOP%d\nWHILELOOP%d:\n", whilecounter, whilecounter2) ;
                return;
            }
        }
        
    }
    else if(match(BEGIN)){
        if (!legal_lookahead(END, 0)){
            fprintf(stderr, "%d: Missing 'end'\n", yylineno) ;
            if (match(SEMI)){
                    advance();
                }else{
                        fprintf( stderr, "%d: Inserting missing semicolon\n", yylineno );
                        return;
                    }  
              
        }else{
            advance();
            while (!match(END)){
                statement();
            }
            return;
        }
    }
    else{
        t=expression();
    }
    if(t){
        freename(t);
    }

    if (match(SEMI)){
        advance();
    }else{
            fprintf( stderr, "%d: Inserting missing semicolon\n", yylineno );
            return;
        }
}

char* expression()
{
    /* expression  -> expression=expression
                    | expression<expression
                    | expression>expression
                    | term expression'

     * expression' -> PLUS term expression'
     *              | MINUS term expression'
     *              | epsilon
     */

   if (legal_lookahead (LT, GT, EQEQ)){
        char *t1;
        t1=expression();
        advance();
        int type;

        if(match(LT))type=1;
        else if(match(GT))type=2;
        else if(match(EQEQ))type=3;

        char *t2,*t3;
        advance();
        t2=expression();
        t3=newname();

        int comparisions = num_COMPARISIONS();

        //fprintf(assemblyfile, "MOV %c,%c\n", Reg, Reg);
        fprintf(assemblyfile, "CMP %c %c\n", Reg[t1[1]-'0'], Reg[t2[1]-'0']);

        switch(type){
            case '1':   fprintf(assemblyfile, "MVI %c 1\nJC COMPARISION%d\n", Reg[t3[1]-'0'], comparisions);
                        fprintf(assemblyfile, "MVI %c 0\nCOMPARISION%d:\n", Reg[t3[1]-'0'], comparisions);
                        break;
            case '2':   fprintf(assemblyfile, "MVI %c 1\nJNZ COMPARISION%d\n", Reg[t3[1]-'0'], comparisions);
                        fprintf(assemblyfile, "MVI %c 0\nCOMPARISION%d:\n", Reg[t3[1]-'0'], comparisions);
                        break;
            case '3':   fprintf(assemblyfile, "MVI %c 1\nJZ COMPARISION%d\n", Reg[t3[1]-'0'], comparisions);
                        fprintf(assemblyfile, "MVI %c 0\nCOMPARISION%d:\n", Reg[t3[1]-'0'], comparisions);
                        break;
        };

        freename(t1);
        freename(t2);

        return t3 ;
    }
    else{
        char *t1,*t2;
        t1=term();
        advance();
        while(match(PLUS) || match(MINUS))
        {
            if(match(PLUS){
                advance();
                t2=factor();
                if(!strcmp(t1,"t0")){
                    fprintf(assemblyfile, "ADD %c\n", Reg[t2[1]-'0']);
                }else{
                    fprintf(assemblyfile, "PUSH A\n");
                    fprintf(assemblyfile, "MOV A,%c\nADD %c\nMOV %c,A\n", Reg[t1[1]-'0'], Reg[t2[1]-'0'], Reg[t1[1]-'0']);
                    fprintf(assemblyfile, "POP A\n");
                }

            }else  if(match(MINUS){
                advance();
                t2=factor();

                if(!strcmp(t1,"t0")){
                    fprintf(assemblyfile, "SUB %c\n", Reg[t2[1]-'0']);
                }else{
                    fprintf(assemblyfile, "PUSH A\n");
                    fprintf(assemblyfile, "MOV A,%c\nSUB %c\nMOV %c,A\n", Reg[t1[1]-'0'], Reg[t2[1]-'0'], Reg[t1[1]-'0']);
                    fprintf(assemblyfile, "POP A\n");
                }
            }
            freename(t2);
        }
        return t1; 
    }
}

char* term()
{
    /*
        term -> factor term'
        term' -> MULT factor term'
                | DIV factor term'
                | epsilon
    */

    char *t1,*t2;
    t1=factor();
    advance();
    while(match(MULT) || match(DIV))
    {
        if(match(MULT){
            advance();
            t2=factor();
            if(!strcmp(t1,"t0")){
                fprintf(assemblyfile, "MUL %c\n", Reg[t2[1]-'0']);
            }else{
                fprintf(assemblyfile, "PUSH A\n");
                fprintf(assemblyfile, "MOV A,%c\nMUL %c\nMOV %c,A\n", Reg[t1[1]-'0'], Reg[t2[1]-'0'], Reg[t1[1]-'0']);
                fprintf(assemblyfile, "POP A\n");
            }

        }else  if(match(DIV){
            advance();
            t2=factor();

            if(!strcmp(t1,"t0")){
                fprintf(assemblyfile, "DIV %c\n", Reg[t2[1]-'0']);
            }else{
                fprintf(assemblyfile, "PUSH A\n");
                fprintf(assemblyfile, "MOV A,%c\nDIV %c\nMOV %c,A\n", Reg[t1[1]-'0'], Reg[t2[1]-'0'], Reg[t1[1]-'0']);
                fprintf(assemblyfile, "POP A\n");
            }
        }
        freename(t2);
    }
    return t1; 
}

char* factor()
{   
    /*
        factor -> NUM_OR_ID
                | LP expression RP
    */

   char *r = NULL;

    if(match(NUM_OR_ID)){
        r=newname();
        int check=0;
        char t[yyleng];
        for(int i=0;i<yyleng;i++){
            t[i]=*(yytext+i);
            if(isdigit(t[i])!=0){
                check=1;
            }  
        }
        if(!check){
            fprintf(assemblyfile, "MVI %c %.*s\n", Reg[r[1]-'0'], yyleng, t);
        }else {
            if(!strcmp(r,"t0")){
                fprintf(assemblyfile, "LDA _%.*s\n", yyleng, t);
            }else{
                fprintf(assemblyfile, "PUSH A\n");
                fprintf(assemblyfile, "LDA _%.*s\nMOV %c,A\nPOP A\n", yyleng, t, Reg[r[1]-'0']);
            }
        }
        advance();
    }

    else if(match(LP))
    {
        advance();
        char *t;
        t=expression();
        if(match(RP))
            advance();
        else
            fprintf( stderr, "%d: Mismatched parenthesis\n", yylineno);
    }
    else
	fprintf( stderr, "%d: Number or identifier expected\n", yylineno);

    return r;
}

#include <stdarg.h>

#define MAXFIRST 16
#define SYNCH	 SEMI

int	legal_lookahead(int first_arg, ... )
{
    /* Simple error detection and recovery. Arguments are a 0-terminated list of
     * those tokens that can legitimately come next in the input. If the list is
     * empty, the end of file must come next. Print an error message if
     * necessary. Error recovery is performed by discarding all input symbols
     * until one that's in the input list is found
     *
     * Return true if there's no error or if we recovered from the error,
     * false if we can't recover.
     */

    va_list  	args;
    int		tok;
    int		lookaheads[MAXFIRST], *p = lookaheads, *current;
    int		error_printed = 0;
    int		rval	      = 0;

    va_start( args, first_arg );

    if( !first_arg )
    {
	if( match(EOI) )
	    rval = 1;
    }
    else
    {
	*p++ = first_arg;
	while( (tok = va_arg(args, int)) && p < &lookaheads[MAXFIRST] )
	    *p++ = tok;

	while( !match( SYNCH ) )
	{
	    for( current = lookaheads; current < p ; ++current )
		if( match( *current ) )
		{
		    rval = 1;
		    goto exit;
		}

	    if( !error_printed )
	    {
		fprintf( stderr, "Line %d: Syntax error\n", yylineno );
		error_printed = 1;
	    }

	    advance();
	}
    }

exit:
    va_end( args );
    return rval;