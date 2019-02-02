#define EOI		0	/* End of input			*/
#define SEMI	1	/* ; 				*/
#define PLUS 	2	/* + 				*/
#define MINUS   3
#define MULT	4	/* * 				*/
#define DIV     5
#define LP		6	/* (				*/
#define RP		7	/* )				*/
#define NUM_OR_ID	8	/* Decimal Number or Identifier */
#define LT      9
#define GT      10
#define EQU     11
#define EQEQ    12
#define IF      13
#define THEN    14
#define WHILE   15
#define DO      16
#define BEGIN   17
#define END     18

extern char *yytext;		/* in lex.c			*/
extern int yyleng;
extern int yylineno;

int lex(void);
int match(int);
void advance(void);