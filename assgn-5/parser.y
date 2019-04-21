%{
#include <bits/stdc++.h>
#include "compiler.h"
using namespace std;

extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(string s){
	return;	
}

%}

%token GTE LTE LT GT NEQ EQ ASGN
%token AND OR NOT
%token PLUS MINUS TIMES DIVIDE MODULO INCREMENT DECREMENT
%token IF ELSE SWITCH CASE DEFAULT BREAK CONTINUE THEN
%token WHILE FOR
%token OPEN_PAR OPEN_CURLY CLOSE_PAR CLOSE_CURLY COMMA SEMI OPEN_BRAC CLOSE_BRAC COLON
%token INT FLOAT VOID RETURN CONST EXTERN STATIC
%token REAL ID
%token ERROR END 

%right AND OR ASGN ELSE THEN
%left MINUS
%left PLUS
%left TIMES
%left DIVIDE MODULO
%left NEG NOT

%start Input

%%

Input:
    Global_Statement Input  { cout<<"Found 0\n"<<endl; }
    | error END             { cout<<"Invalid Syntax\n"<<endl; YYABORT;}
	| END					{ cout<<"Found END\n"<<endl; YYABORT; }
;

Global_Statement:
    Var_Decl           { cout<<"Found 1\n"<<endl; }
    | Func_Decl SEMI               { cout<<"Found 2\n"<<endl; }
    | Func_Defn            { cout<<"Found 3\n"<<endl; }
;

Var_Decl:
    INT Var_List SEMI               { cout<<"Found 4\n"<<endl; }
    | FLOAT Var_List SEMI               { cout<<"Found 5\n"<<endl; }
    | CONST INT Var_List SEMI               { cout<<"Found 4\n"<<endl; }
    | CONST FLOAT Var_List SEMI               { cout<<"Found 5\n"<<endl; }
    | STATIC INT Var_List SEMI               { cout<<"Found 4\n"<<endl; }
    | STATIC FLOAT Var_List SEMI               { cout<<"Found 5\n"<<endl; }
    | EXTERN INT Var_List SEMI               { cout<<"Found 4\n"<<endl; }
    | EXTERN FLOAT Var_List SEMI               { cout<<"Found 5\n"<<endl; }
;

Var_List:
    Var COMMA Var_List              { cout<<"Found 6\n"<<endl; }
    | Var_Asgn COMMA Var_List               { cout<<"Found 7\n"<<endl; }
    | Var               { cout<<"Found 8\n"<<endl; }
    | Var_Asgn              { cout<<"Found 9\n"<<endl; }
;

Var:
    ID              { cout<<"Found 10\n"<<endl; }
    | ID OPEN_BRAC Expression COMMA Dim_List CLOSE_BRAC             { cout<<"Found 11\n"<<endl; }
    | ID Brac_Dim_List              { cout<<"Found 12\n"<<endl; }
;

Var_Asgn:
    Var ASGN Expression             { cout<<"Found 13\n"<<endl; }
;

Dim_List:
    Expression COMMA Dim_List               { cout<<"Found 14\n"<<endl; }
    | Expression                { cout<<"Found 15\n"<<endl; }
;

Brac_Dim_List:
    OPEN_BRAC Expression CLOSE_BRAC Brac_Dim_List               { cout<<"Found 16\n"<<endl; }
    | OPEN_BRAC Expression CLOSE_BRAC               { cout<<"Found 17\n"<<endl; }
;

Func_Decl:
    INT ID OPEN_PAR Decl_Param_List CLOSE_PAR               { cout<<"Found 18\n"<<endl; }
    | FLOAT ID OPEN_PAR Decl_Param_List CLOSE_PAR               { cout<<"Found 19\n"<<endl; }
    | VOID ID OPEN_PAR Decl_Param_List CLOSE_PAR                { cout<<"Found 20\n"<<endl; }
    | INT ID OPEN_PAR CLOSE_PAR             { cout<<"Found 21\n"<<endl; }
    | FLOAT ID OPEN_PAR CLOSE_PAR               { cout<<"Found 22\n"<<endl; }
    | VOID ID OPEN_PAR CLOSE_PAR                { cout<<"Found 23\n"<<endl; }
;

Decl_Param_List:
    Decl_Param COMMA Decl_Param_List                { cout<<"Found 24\n"<<endl; }
    | Defn_Param COMMA Decl_Param_List              { cout<<"Found 25\n"<<endl; }
    | Decl_Param                { cout<<"Found 26\n"<<endl; }
    | Defn_Param                { cout<<"Found 27\n"<<endl; }
;

Func_Call:
    ID OPEN_PAR Param_List CLOSE_PAR                { cout<<"Found 28\n"<<endl; }
;

Param_List:
    Expression COMMA Param_List             { cout<<"Found 29\n"<<endl; }
    | Expression                { cout<<"Found 30\n"<<endl; }
;

Func_Defn:
    Func_Decl Block             { cout<<"Found 31\n"<<endl; }
;

Decl_Param:
    INT             { cout<<"Found 33\n"<<endl; }
    | FLOAT             { cout<<"Found 34\n"<<endl; }
;

Defn_Param:
    INT ID              { cout<<"Found 35\n"<<endl; }
    | FLOAT ID              { cout<<"Found 36\n"<<endl; }
;

Statements:
    Statement Statements                { cout<<"Found 37\n"<<endl; }
    | Statement             { cout<<"Found 38\n"<<endl; }
;

Statement:
    Non_Conditional_Statement               { cout<<"Found 39\n"<<endl; }
    | Conditional_Block             { cout<<"Found 40\n"<<endl; }
;

Non_Conditional_Statement:
    Block               { cout<<"Found 41\n"<<endl; }
    | Loop_Block                { cout<<"Found 42\n"<<endl; }
    | Var_Decl                  { cout<<"Found Var_Decl_Statement\n"<<endl; }
    | Expression SEMI               { cout<<"Found 43\n"<<endl; }
    | BREAK SEMI                { cout<<"Found 44\n"<<endl; }
    | CONTINUE SEMI             { cout<<"Found 45\n"<<endl; }
    | RETURN Expression SEMI                { cout<<"Found 46\n"<<endl; }
    | SEMI              { cout<<"Found 47\n"<<endl; }
;

Block:
    OPEN_CURLY Statements CLOSE_CURLY               { cout<<"Found 48\n"<<endl; }
;

Loop_Block:
    FOR OPEN_PAR For_Control CLOSE_PAR Statement                { cout<<"Found 49\n"<<endl; }
    | WHILE OPEN_PAR Condition CLOSE_PAR Statement              { cout<<"Found 50\n"<<endl; }
;

For_Control:
    Init_Statement Condition SEMI Expression                { cout<<"Found 51\n"<<endl; }
    | Init_Statement SEMI Expression                { cout<<"Found 52\n"<<endl; }
;

Init_Statement:
    Expression SEMI             { cout<<"Found 53\n"<<endl; }
    | SEMI              { cout<<"Found 54\n"<<endl; }
;

Conditional_Block:
    If_Else_Block               { cout<<"Found 55\n"<<endl; }
    | Switch_Block              { cout<<"Found 56\n"<<endl; }
;

If_Else_Block:
    IF OPEN_PAR Condition CLOSE_PAR Statement %prec THEN                { cout<<"Found 57\n"<<endl; }
    | IF OPEN_PAR Condition CLOSE_PAR Statement ELSE Statement              { cout<<"Found 58\n"<<endl; }
;

Switch_Block:
    SWITCH OPEN_PAR Constant_Expression CLOSE_PAR OPEN_CURLY Switch_Body CLOSE_CURLY                { cout<<"Found 59\n"<<endl; }
    | SWITCH OPEN_PAR Var CLOSE_PAR OPEN_CURLY Switch_Body CLOSE_CURLY              { cout<<"Found 60\n"<<endl; }
;

Switch_Body:
    CASE Constant_Expression COLON Statements       { cout<<"Found 61\n"<<endl; }
    | DEFAULT COLON Statements                      { cout<<"Found 62\n"<<endl; }
;

Condition:
	OPEN_PAR Condition CLOSE_PAR            { cout<<"Found 63\n"<<endl; }
    | NOT Condition                         { cout<<"Found 64\n"<<endl; }
	| Condition OR Condition                { cout<<"Found 65\n"<<endl; }
	| Condition AND Condition               { cout<<"Found 66\n"<<endl; }
	| Expression LT Expression              { cout<<"Found 67\n"<<endl; }
	| Expression GT Expression              { cout<<"Found 68\n"<<endl; }
	| Expression LTE Expression             { cout<<"Found 69\n"<<endl; }
	| Expression GTE Expression             { cout<<"Found 70\n"<<endl; }
	| Expression EQ Expression              { cout<<"Found 71\n"<<endl; }
	| Expression NEQ Expression             { cout<<"Found 72\n"<<endl; }
;

Constant_Expression:
    REAL                                                                { cout<<"Found 73\n"<<endl; }
    | OPEN_PAR Constant_Expression CLOSE_PAR                            { cout<<"Found 74\n"<<endl; }	
    | Constant_Expression PLUS Constant_Expression	                    { cout<<"Found 75\n"<<endl; }
    | Constant_Expression MINUS Constant_Expression                     { cout<<"Found 76\n"<<endl; }
    | Constant_Expression TIMES Constant_Expression                     { cout<<"Found 77\n"<<endl; }
	| Constant_Expression DIVIDE Constant_Expression                    { cout<<"Found 78\n"<<endl; }
    | Constant_Expression MODULO Constant_Expression                    { cout<<"Found 79\n"<<endl; }
    | MINUS Constant_Expression %prec NEG                               { cout<<"Found 80\n"<<endl; }
;

Expression:
    REAL		                                    { cout<<"Found 81\n"<<endl; }
    | Var                                           { cout<<"Found 82\n"<<endl; }
    | Var_Asgn                                      { cout<<"Found 83\n"<<endl; }
    | Func_Call                                     { cout<<"Found 84\n"<<endl; }
    | Var INCREMENT                                 { cout<<"Found 85\n"<<endl; }
    | Var DECREMENT                                 { cout<<"Found 86\n"<<endl; }
    | INCREMENT Var                                 { cout<<"Found 87\n"<<endl; }
    | DECREMENT Var                                 { cout<<"Found 88\n"<<endl; }
	| OPEN_PAR Expression CLOSE_PAR	                { cout<<"Found 89\n"<<endl; }
	| Expression PLUS Expression	                { cout<<"Found 90\n"<<endl; }
	| Expression MINUS Expression	                { cout<<"Found 91\n"<<endl; }
	| Expression TIMES Expression	                { cout<<"Found 92\n"<<endl; }
	| Expression DIVIDE Expression	                { cout<<"Found 93\n"<<endl; }
    | Expression MODULO Expression                  { cout<<"Found 94\n"<<endl; }
	| MINUS Expression %prec NEG	                { cout<<"Found 95\n"<<endl; }
;
    
%%

 int main(int argc, char *argv[]){
    yyin = fopen(argv[1], "r");
    yyparse();
    fclose(yyin);
 }