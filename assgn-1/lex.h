#define EOI		0	/* End of input	*/
#define SEMI	1	/* ; */
#define PLUS 	2	/* + */
#define MINUS   3   /* - */
#define MULT	4	/* * */
#define DIV     5   /* / */
#define LP		6	/* ( */
#define RP		7	/* ) */
#define NUM_OR_ID	8	/* Decimal Number or Identifier */
#define LT      9   /* < */
#define GT      10  /* > */
#define EQU     11  /* = */
#define EQEQ    12  /* := */
#define IF      13  /* if */
#define THEN    14  /* then */
#define WHILE   15  /* while */
#define DO      16  /* do */
#define BEGIN   17  /* begin */
#define END     18  /* end */

extern char *yytext;		/* are the three 'yy' are in lex.c */
extern int yyleng;
extern int yylineno;

int lex(void);      /* returns the token */
int match(int);     /* returns if the lexeme matches with the given token */
void advance(void); /* determines the token ahead */