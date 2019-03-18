%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(char *s){
	return;
}
%}

%token SELECT PROJECT PRODUCT JOIN
%token OPEN_PAR CLOSE_PAR
%token GT LT GTE LTE EQ NEQ
%token AND OR
%token PLUS MINUS TIMES DIVIDE
%token COMMA DOT
%token STRING NUMBER ID
%token NEWLINE ERROR END

%left PLUS MINUS
%left TIMES DIVIDE
%left NEG
%right AND OR

%start Input

%%

Input:

	| Input Line
;

Line:
	Select NEWLINE			{printf("Valid Syntax\n");}
	| Project NEWLINE		{printf("Valid Syntax\n");}
	| Product NEWLINE		{printf("Valid Syntax\n");}
	| Join NEWLINE			{printf("Valid Syntax\n");}
	| error NEWLINE 		{printf("Invalid Syntax\n");}
	| Select END			{printf("Valid Syntax\n"); YYABORT;}
	| Project END			{printf("Valid Syntax\n"); YYABORT;}
	| Product END			{printf("Valid Syntax\n"); YYABORT;}
	| Join END				{printf("Valid Syntax\n"); YYABORT;}
;

Select:
	SELECT LT Condition GT OPEN_PAR ID CLOSE_PAR
;

Project:
	PROJECT LT Attributes GT OPEN_PAR ID CLOSE_PAR
;

Product:
	OPEN_PAR ID CLOSE_PAR PRODUCT OPEN_PAR ID CLOSE_PAR
;

Join:
	OPEN_PAR ID CLOSE_PAR JOIN LT Condition GT  OPEN_PAR ID CLOSE_PAR
;

Attributes:
	Attributes COMMA Column_Name
	| Column_Name
;

Column_Name:
	ID
	| ID DOT ID
;

Condition:
	OPEN_PAR Condition CLOSE_PAR
	| Condition OR Condition
	| Condition AND Condition
	| Expression LT Expression
	| Expression GT Expression
	| Expression LTE Expression
	| Expression GTE Expression
	| Expression EQ Expression
	| Expression NEQ Expression
;

Expression:
	NUMBER
	| Column_Name
	| STRING
	| OPEN_PAR Expression CLOSE_PAR
	| Expression PLUS Expression
	| Expression MINUS Expression
	| Expression TIMES Expression
	| Expression DIVIDE Expression
	| MINUS Expression %prec NEG
;

%%

int main() {
	yyin = fopen("ra.txt","r");
	yyparse();
	fclose(yyin);
}