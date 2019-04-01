%{
#include <bits/stdc++.h>
#include "tables.h"

using namespace std;

extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(string s){
	return;	
}
Table *table1, *table2, *result;
int linenum = 1;
%}

%union
{
	Node *node;
	DataType valueType;
}

%token SELECT PROJECT PRODUCT JOIN
%token OPEN_PAR CLOSE_PAR
%token GT LT GTE LTE EQ NEQ
%token AND OR
%token PLUS MINUS TIMES DIVIDE
%token COMMA DOT
%token <node> STRING NUMBER ID
%token NEWLINE ERROR END

%type <node> Attributes Condition ColumnName Expression

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
	Select					
	| Project				
	| Product				
	| Join					
	| error NEWLINE 		{ cout<<"Invalid Syntax\n"<<endl; }
	| END					{ YYABORT; }
;

Select:
	SELECT LT Condition GT OPEN_PAR ID CLOSE_PAR NEWLINE		{cout<<"Valid Syntax"<<endl; tableSelectResult($6->str, $3);}
	|SELECT LT Condition GT OPEN_PAR ID CLOSE_PAR END			{cout<<"Valid Syntax"<<endl; tableSelectResult($6->str, $3); YYABORT;}
;

Project:
	PROJECT LT Attributes GT OPEN_PAR ID CLOSE_PAR NEWLINE		{cout<<"Valid Syntax"<<endl; tableProjectResult($6->str, $3);}
	|PROJECT LT Attributes GT OPEN_PAR ID CLOSE_PAR END			{cout<<"Valid Syntax"<<endl; tableProjectResult($6->str, $3); YYABORT;}
;

Product:
	OPEN_PAR ID CLOSE_PAR PRODUCT OPEN_PAR ID CLOSE_PAR NEWLINE		{cout<<"Valid Syntax"<<endl; tableProductResult($2->str, $6->str);}
	|OPEN_PAR ID CLOSE_PAR PRODUCT OPEN_PAR ID CLOSE_PAR	END			{cout<<"Valid Syntax"<<endl; tableProductResult($2->str, $6->str); YYABORT;}
;

Join:
	OPEN_PAR ID CLOSE_PAR JOIN LT Condition GT  OPEN_PAR ID CLOSE_PAR NEWLINE	{cout<<"Valid Syntax"<<endl; tableEquiJoinResult($2->str, $9->str, $6);}
	|OPEN_PAR ID CLOSE_PAR JOIN LT Condition GT  OPEN_PAR ID CLOSE_PAR END		{cout<<"Valid Syntax"<<endl; tableEquiJoinResult($2->str, $9->str, $6); YYABORT;}
;

Attributes:
	Attributes COMMA ColumnName		{$$ = new Node; $$->dataType = dt_attr; $$->child1 = $1; $$->child2 = $3;}
	| ColumnName					{$$ = new Node; $$->dataType = dt_attr; $$->child1 = NULL; $$->child2 = $1;}
;

ColumnName:
	ID								{$$ = new Node; $$->dataType = dt_col; $$->child1 = $1; $$->child2 = NULL;}
	| ID DOT ID						{$$ = new Node; $$->dataType = dt_col; $$->child1 = $1; $$->child2 = $3;}
;

Condition:
	OPEN_PAR Condition CLOSE_PAR	{$$ = new Node; $$->dataType = dt_cond; $$->comp = cp_none; $$->comb = cb_none; $$->child1 = $2; $$->child2 = NULL;}
	| Condition OR Condition		{$$ = new Node; $$->dataType = dt_cond; $$->comp = cp_none; $$->comb = cb_or; $$->child1 = $1; $$->child2 = $3;}
	| Condition AND Condition		{$$ = new Node; $$->dataType = dt_cond; $$->comp = cp_none; $$->comb = cb_and; $$->child1 = $1; $$->child2 = $3;}
	| Expression LT Expression		{$$ = new Node; $$->dataType = dt_cond; $$->comp = cp_lt; $$->comb = cb_none; $$->child1 = $1; $$->child2 = $3;}
	| Expression GT Expression		{$$ = new Node; $$->dataType = dt_cond; $$->comp = cp_gt; $$->comb = cb_none; $$->child1 = $1; $$->child2 = $3;}
	| Expression LTE Expression		{$$ = new Node; $$->dataType = dt_cond; $$->comp = cp_lte; $$->comb = cb_none; $$->child1 = $1; $$->child2 = $3;}
	| Expression GTE Expression		{$$ = new Node; $$->dataType = dt_cond; $$->comp = cp_gte; $$->comb = cb_none; $$->child1 = $1; $$->child2 = $3;}
	| Expression EQ Expression		{$$ = new Node; $$->dataType = dt_cond; $$->comp = cp_eq; $$->comb = cb_none; $$->child1 = $1; $$->child2 = $3;}
	| Expression NEQ Expression		{$$ = new Node; $$->dataType = dt_cond; $$->comp = cp_neq; $$->comb = cb_none; $$->child1 = $1; $$->child2 = $3;}
;

Expression:
	NUMBER							{$$ = new Node; $$->dataType = dt_expr; $$->expr = et_num; $$->child1 = $1; $$->child2 = NULL;}
	| ColumnName					{$$ = new Node; $$->dataType = dt_expr; $$->expr = et_col; $$->child1 = $1; $$->child2 = NULL;}
	| STRING						{$$ = new Node; $$->dataType = dt_expr; $$->expr = et_str; $$->child1 = $1; $$->child2 = NULL; $$->child1->str.pop_back(); $$->child1->str.erase(0,1);}
	| OPEN_PAR Expression CLOSE_PAR	{$$ = new Node; $$->dataType = dt_expr; $$->expr = et_none; $$->child1 = $2; $$->child2 = NULL;}
	| Expression PLUS Expression	{$$ = new Node; $$->dataType = dt_expr; $$->expr = et_plus; $$->child1 = $1; $$->child2 = $3;}
	| Expression MINUS Expression	{$$ = new Node; $$->dataType = dt_expr; $$->expr = et_minus; $$->child1 = $1; $$->child2 = $3;}
	| Expression TIMES Expression	{$$ = new Node; $$->dataType = dt_expr; $$->expr = et_times; $$->child1 = $1; $$->child2 = $3;}
	| Expression DIVIDE Expression	{$$ = new Node; $$->dataType = dt_expr; $$->expr = et_divide; $$->child1 = $1; $$->child2 = $3;}
	| MINUS Expression %prec NEG	{$$ = new Node; $$->dataType = dt_expr; $$->expr = et_neg; $$->child1 = $2; $$->child2 = NULL;}
;

%%

int main() {
	yyin = fopen("ra.txt","r");
	yyparse();
	fclose(yyin);
}