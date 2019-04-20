%{
#include <bits/stdc++.h>
#include "compiler.h"
using namespace std;

extern int yylex();
extern int yyparse();

%}

%token GTE LTE LT GT NEQ EQ ASGN
%token AND OR NOT
%token PLUS MINUS TIMES DIVIDE MODULO INCREMENT DECREMENT
%token IF ELSE SWITCH CASE DEFAULT BREAK CONTINUE
%token WHILE FOR
%token OPEN_PAR OPEN_CURLY CLOSE_PAR CLOSE_CURLY COMMA SEMI OPEN_BRAC CLOSE_BRAC COLON
%token INT FLOAT VOID MAIN
%token INT_NUMBER FLOAT_NUMBER ID
%token NEWLINE ERROR END 

%left PLUS MINUS
%left TIMES DIVIDE MODULO
%left NEG NOT
%right AND OR

%start Input

%%

Input:
    | Var_Decl SEMI Input
    | Func_Decl SEMI Input
    | Func_Defn Input
    | error END             { cout<<"Invalid Syntax\n"<<endl; }
	| END					{ YYABORT; }
;

Var_Decl:
    INT Var_List 
    | FLOAT Var_List 
;

Var_List:
    Var COMMA Var_List
    | Var_Asgn COMMA Var_List
    | Var
    | Var_Asgn
;

Var:
    ID
    | ID OPEN_BRAC Dim_List CLOSE_BRAC
    | ID Brac_Dim_List
;

Var_Asgn:
    Var ASGN Expression
;

Dim_List:
    INT_NUMBER COMMA Dim_List
    | INT_NUMBER
;

Brac_Dim_List:
    OPEN_BRAC INT_NUMBER CLOSE_BRAC Brac_Dim_List
    | OPEN_BRAC INT_NUMBER CLOSE_BRAC
;

Func_Decl:
    INT ID OPEN_PAR Decl_Param_List CLOSE_PAR 
    | FLOAT ID OPEN_PAR Decl_Param_List CLOSE_PAR 
    | VOID ID OPEN_PAR Decl_Param_List CLOSE_PAR 
;

Decl_Param_List:
    INT COMMA Decl_Param_List
    | FLOAT COMMA Decl_Param_List
    | INT ID COMMA Decl_Param_List
    | FLOAT ID COMMA Decl_Param_List
;

Func_Call:
    ID OPEN_PAR Param_List CLOSE_PAR 
;

Param_List:
    ID COMMA Param_List
    | INT_NUMBER COMMA Param_List
    | FLOAT_NUMBER COMMA Param_List
    | Func_Call COMMA Param_List
    | ID
    | INT_NUMBER
    | FLOAT_NUMBER
    | Func_Call
;

Func_Defn:
    INT ID OPEN_PAR Defn_Param_List CLOSE_PAR Func_Body
    | FLOAT ID OPEN_PAR Defn_Param_List CLOSE_PAR Func_Body
    | VOID ID OPEN_PAR Defn_Param_List CLOSE_PAR Func_Body
;

Func_Body:
    OPEN_CURLY Statements CLOSE_CURLY
;

Defn_Param_List:
    INT ID COMMA Defn_Param_List
    | FLOAT ID COMMA Defn_Param_List
;

Statements:
    Statement Statements
    | Statement
    | SEMI
;

Statement:
    Loop_Block
    | Conditional_Block
    | Expression SEMI
    | BREAK SEMI
    | CONTINUE SEMI
    | SEMI
;

Block:
    OPEN_CURLY Statements CLOSE_CURLY
    | Statement
;

Loop_Block:
    FOR OPEN_PAR For_Control CLOSE_PAR Block
    | WHILE OPEN_PAR Condition CLOSE_PAR Block
;

For_Control:
    Init_Statement Condition SEMI Expression
    | Init_Statement SEMI Expression
;

Init_Statement:
    Expression SEMI
    | SEMI
;

Conditional_Block:
    If_Else_Block
    | Switch_Block
;

If_Else_Block:
    IF OPEN_PAR Condition CLOSE_PAR Block ELSE Block
    | IF OPEN_PAR Condition CLOSE_PAR Block ELSE If_Else_Block
    | IF OPEN_PAR Condition CLOSE_PAR Block
;

Switch_Block:
    SWITCH OPEN_PAR Constant_Expression CLOSE_PAR OPEN_CURLY Switch_Body CLOSE_CURLY
    | SWITCH OPEN_PAR Var CLOSE_PAR OPEN_CURLY Switch_Body CLOSE_CURLY
;

Switch_Body:
    CASE Constant_Expression COLON Statements
    | DEFAULT COLON Statements
;

Condition:
	OPEN_PAR Condition CLOSE_PAR
    | NOT Condition
	| Condition OR Condition
	| Condition AND Condition
	| Expression LT Expression
	| Expression GT Expression
	| Expression LTE Expression
	| Expression GTE Expression
	| Expression EQ Expression
	| Expression NEQ Expression
;

Constant_Expression:
    INT_NUMBER
	| OPEN_PAR Constant_Expression CLOSE_PAR	
	| Constant_Expression PLUS Constant_Expression	
	| Constant_Expression MINUS Constant_Expression	
	| Constant_Expression TIMES Constant_Expression	
	| Constant_Expression DIVIDE Constant_Expression	
    | Constant_Expression MODULO Constant_Expression
	| MINUS Constant_Expression %prec NEG	
;

Expression:
	INT_NUMBER						
	| FLOAT_NUMBER				
	| Var
    | Var_Asgn
    | Func_Call
    | Var INCREMENT
    | Var DECREMENT
    | INCREMENT Var
    | DECREMENT Var
	| OPEN_PAR Expression CLOSE_PAR	
	| Expression PLUS Expression	
	| Expression MINUS Expression	
	| Expression TIMES Expression	
	| Expression DIVIDE Expression	
    | Expression MODULO Expression
	| MINUS Expression %prec NEG	
;
    
%%

 int main(){
     yyparse();
 }

