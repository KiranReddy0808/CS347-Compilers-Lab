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

%union
{
	Node *node;
}

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
	Global_Statement Input  {  }
	| error END             { cout<<"Invalid Syntax\n"<<endl; YYABORT; }
	| END					{ YYABORT; }
;

Global_Statement:
	Var_Decl           		{  }
	| Func_Decl SEMI        {  }
	| Func_Defn				{  }
;

Var_Decl:
	INT Var_List SEMI                   {  }
	| FLOAT Var_List SEMI               {  }
	| CONST INT Var_List SEMI           {  }
	| CONST FLOAT Var_List SEMI         {  }
	| STATIC INT Var_List SEMI          {  }
	| STATIC FLOAT Var_List SEMI        {  }
	| EXTERN INT Var_List SEMI          {  }
	| EXTERN FLOAT Var_List SEMI        {  }
;

Var_List:
	Var COMMA Var_List              {  }
	| Var_Asgn COMMA Var_List               {  }
	| Var               {  }
	| Var_Asgn              {  }
;

Var:
	ID              {  }
	| ID OPEN_BRAC Expression COMMA Dim_List CLOSE_BRAC             {  }
	| ID Brac_Dim_List              {  }
;

Var_Asgn:
	Var ASGN Expression             {  }
;

Dim_List:
	Expression COMMA Dim_List               {  }
	| Expression                {  }
;

Brac_Dim_List:
	OPEN_BRAC Expression CLOSE_BRAC Brac_Dim_List               {  }
	| OPEN_BRAC Expression CLOSE_BRAC               {  }
;

Func_Decl:
	INT ID OPEN_PAR Decl_Param_List CLOSE_PAR               {  }
	| FLOAT ID OPEN_PAR Decl_Param_List CLOSE_PAR               {  }
	| VOID ID OPEN_PAR Decl_Param_List CLOSE_PAR                {  }
	| INT ID OPEN_PAR CLOSE_PAR             {  }
	| FLOAT ID OPEN_PAR CLOSE_PAR               {  }
	| VOID ID OPEN_PAR CLOSE_PAR                {  }
;

Decl_Param_List:
	Decl_Param COMMA Decl_Param_List                {  }
	| Defn_Param COMMA Decl_Param_List              {  }
	| Decl_Param                {  }
	| Defn_Param                {  }
;

Func_Call:
	ID OPEN_PAR Param_List CLOSE_PAR                {  }
;

Param_List:
	Expression COMMA Param_List             {  }
	| Expression                {  }
;

Func_Defn:
	Func_Decl Block             {  }
;

Decl_Param:
	INT             {  }
	| FLOAT             {  }
;

Defn_Param:
	INT ID              {  }
	| FLOAT ID              {  }
;

Statements:
	Statement Statements                {  }
	| Statement             {  }
;

Statement:
	Non_Conditional_Statement               {  }
	| Conditional_Block             {  }
;

Non_Conditional_Statement:
	Block               {  }
	| Loop_Block                {  }
	| Var_Decl                  {  }
	| Expression SEMI               {  }
	| BREAK SEMI                {  }
	| CONTINUE SEMI             {  }
	| RETURN Expression SEMI                {  }
	| SEMI              {  }
;

Block:
	OPEN_CURLY Statements CLOSE_CURLY               {  }
;

Loop_Block:
	FOR OPEN_PAR For_Control CLOSE_PAR Statement                {  }
	| WHILE OPEN_PAR Condition CLOSE_PAR Statement              {  }
;

For_Control:
	Init_Statement Condition SEMI Expression                {  }
	| Init_Statement SEMI Expression                {  }
;

Init_Statement:
	Expression SEMI                                 {  }
	| SEMI                                          {  }
;

Conditional_Block:
	If_Else_Block               {  }
	| Switch_Block              {  }
;

If_Else_Block:
	IF OPEN_PAR Condition CLOSE_PAR Statement %prec THEN                {  }
	| IF OPEN_PAR Condition CLOSE_PAR Statement ELSE Statement              {  }
;

Switch_Block:
	SWITCH OPEN_PAR Constant_Expression CLOSE_PAR OPEN_CURLY Switch_Body CLOSE_CURLY                {  }
	| SWITCH OPEN_PAR Var CLOSE_PAR OPEN_CURLY Switch_Body CLOSE_CURLY              {  }
;

Switch_Body:
	CASE Constant_Expression COLON Statements       {  }
	| DEFAULT COLON Statements                      {  }
;

Condition:
	OPEN_PAR Condition CLOSE_PAR            {  }
	| NOT Condition                         {  }
	| Condition OR Condition                {  }
	| Condition AND Condition               {  }
	| Expression LT Expression              {  }
	| Expression GT Expression              {  }
	| Expression LTE Expression             {  }
	| Expression GTE Expression             {  }
	| Expression EQ Expression              {  }
	| Expression NEQ Expression             {  }
;

Constant_Expression:
	REAL                                                                {  }
	| OPEN_PAR Constant_Expression CLOSE_PAR                            {  }	
	| Constant_Expression PLUS Constant_Expression	                    {  }
	| Constant_Expression MINUS Constant_Expression                     {  }
	| Constant_Expression TIMES Constant_Expression                     {  }
	| Constant_Expression DIVIDE Constant_Expression                    {  }
	| Constant_Expression MODULO Constant_Expression                    {  }
	| MINUS Constant_Expression %prec NEG                               {  }
;

Expression:
	REAL											{  }
	| Var                                           {  }
	| Var_Asgn                                      {  }
	| Func_Call                                     {  }
	| Var INCREMENT                                 {  }
	| Var DECREMENT                                 {  }
	| INCREMENT Var                                 {  }
	| DECREMENT Var                                 {  }
	| OPEN_PAR Expression CLOSE_PAR	                {  }
	| Expression PLUS Expression	                {  }
	| Expression MINUS Expression	                {  }
	| Expression TIMES Expression	                {  }
	| Expression DIVIDE Expression	                {  }
	| Expression MODULO Expression                  {  }
	| MINUS Expression %prec NEG	                {  }
;
	
%%

 int main(int argc, char *argv[]){
	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);
 }