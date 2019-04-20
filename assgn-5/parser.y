%{
#include <bits/stdc++.h>
#include "compiler.h"
using namespace std;

extern int yylex();
extern int yyparse();
extern FILE* yyin;

%}

%token GTE LTE LT GT NEQ EQ ASGN
%token AND OR NOT
%token PLUS MINUS TIMES DIVIDE MODULO
%token IF ELSE SWITCH CASE DEFAULT
%token WHILE FOR
%token OPEN_PAR OPEN_CURLY CLOSE_PAR CLOSE_CURLY COMMA SEMI OPEN_BRAC CLOSE_BRAC COLON
%token INT FLOAT VOID MAIN
%token <> INT_NUMBER FLOAT_NUMBER ID
%token NEWLINE ERROR END 

%start .....

%%

%%

 int main(){
     yyin = fopen();
     
     /* Lexical analysis and Parsing */
     yyparse();

     /* Semantic Analysis*/
     /* IC Generation */

     fclose(yyin);
 }

