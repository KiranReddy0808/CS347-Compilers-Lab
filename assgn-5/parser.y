%{
#include <bits/stdc++.h>
#include "compiler.h"
using namespace std;

extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(string s);
bool syntax_error = false;
Node* parseTree = new Node("parse_tree","");
vector <SymbolNode*> curParamList;
extern int yylineno;
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
%token <node> REAL ID
%token ERROR END 

%type <node> Var_Decl Var_List Var Var_Asgn Dim_List Brac_Dim_List 
%type <node> Func_Decl Decl_Param_List Func_Call Param_List Func_Defn Decl_Param Defn_Param 
%type <node> Statements Statement Non_Conditional_Statement Block Loop_Block For_Control Init_Statement 
%type <node> Conditional_Block If_Else_Block Switch_Block Switch_Body Condition Constant_Expression Expression

%right AND OR ASGN ELSE THEN
%left MINUS
%left PLUS
%left TIMES
%left DIVIDE MODULO
%left NEG NOT

%start Input

%define parse.error verbose

%%

Input:
	Global_Statement Input	{  }
	| END					{ YYABORT; }
;

Global_Statement:
	Var_Decl				{ parseTree->childs.push_back($1); }
	| Func_Decl SEMI		{ parseTree->childs.push_back($1); }
	| Func_Defn				{ parseTree->childs.push_back($1); }
;

Var_Decl:
	INT Var_List SEMI					
		{
			$$ = new Node("var_decl", "int");
			$$->childs.push_back($2);

		}
	| FLOAT Var_List SEMI				
		{
			$$ = new Node("var_decl", "flt");
			$$->childs.push_back($2);

		}
	| CONST INT Var_List SEMI			
		{
			$$ = new Node("var_decl", "const_int");
			$$->childs.push_back($3);

		}
	| CONST FLOAT Var_List SEMI			
		{
			$$ = new Node("var_decl", "flt");
			$$->childs.push_back($3);

		}
	| STATIC INT Var_List SEMI			
		{
			$$ = new Node("var_decl", "static_int");
			$$->childs.push_back($3);

		}
	| STATIC FLOAT Var_List SEMI		
		{
			$$ = new Node("var_decl", "flt");
			$$->childs.push_back($3);

		}
	| EXTERN INT Var_List SEMI			
		{
			$$ = new Node("var_decl", "extern_int");
			$$->childs.push_back($3);

		}
	| EXTERN FLOAT Var_List SEMI		
		{
			$$ = new Node("var_decl", "flt");
			$$->childs.push_back($3);

		}
;

Var_List:
	Var COMMA Var_List					
		{
			$$ = new Node("var_list", "var_more");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Var_Asgn COMMA Var_List			
		{
			$$ = new Node("var_list", "var_asgn_more");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Var								
		{
			$$ = new Node("var_list", "var");
			$$->childs.push_back($1);

		}
	| Var_Asgn							
		{
			$$ = new Node("var_list", "var_asgn");
			$$->childs.push_back($1);

		}
;

Var:
	ID															
		{
			$$ = new Node("var", "id");

		}
	| ID OPEN_BRAC Expression COMMA Dim_List CLOSE_BRAC			
		{
			$$ = new Node("var", "id_dim_list");
			$$->childs.push_back($3);
			$$->childs.push_back($5);

		}
	| ID Brac_Dim_List											
		{
			$$ = new Node("var", "id_brac");
			$$->childs.push_back($2);

		}
;

Var_Asgn:
	Var ASGN Expression											
		{
			$$ = new Node("var_asgn", "default");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
;

Dim_List:	
	Expression COMMA Dim_List									
		{
			$$ = new Node("dim_list", "more");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
		}

	| Expression												
		{
			$$ = new Node("dim_list", "one");
			$$->childs.push_back($1);

		}
;

Brac_Dim_List:
	OPEN_BRAC Expression CLOSE_BRAC Brac_Dim_List	
		{			
			$$ = new Node("brac_list", "more");
			$$->childs.push_back($2);
			$$->childs.push_back($4);

		}
	| OPEN_BRAC Expression CLOSE_BRAC	
		{						
			$$ = new Node("brac_list", "one");
			$$->childs.push_back($2);

		}
;

Func_Decl:
	INT ID OPEN_PAR Decl_Param_List CLOSE_PAR					
		{
			$$ = new Node("func_decl", "int_plist");
			$$->childs.push_back($4);
			for (int i=0; i<$4->paramList.size(); i++){
				cout << $4->paramList[i]->dataType << "," << $4->paramList[i]->valueType <<endl;
			}
		}
	| FLOAT ID OPEN_PAR Decl_Param_List CLOSE_PAR				
		{
			$$ = new Node("func_decl", "float_plist");
			$$->childs.push_back($4);

		}
	| VOID ID OPEN_PAR Decl_Param_List CLOSE_PAR				
		{
			$$ = new Node("func_decl", "void_plist");
			$$->childs.push_back($4);

		}
	| INT ID OPEN_PAR CLOSE_PAR									
		{
			$$ = new Node("func_decl", "int_none");

		}
	| FLOAT ID OPEN_PAR CLOSE_PAR								
		{
			$$ = new Node("func_decl", "float_none");

		}
	| VOID ID OPEN_PAR CLOSE_PAR								
		{
			$$ = new Node("func_decl", "void_none");

		}
;

Decl_Param_List:
	Decl_Param COMMA Decl_Param_List				
		{
			$$ = new Node("decl_plist", "decl_type_more");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			$$->paramList = $3->paramList;
			$$->paramList.push_back($1);
		}
	| Defn_Param COMMA Decl_Param_List				
		{
			$$ = new Node("decl_plist", "defn_type_more");
			$$->childs.push_back($1);
			$$->paramList = $3->paramList;
			$$->paramList.push_back($1);
		}
	| Decl_Param									
		{
			$$ = new Node("decl_plist", "decl_type_one");
			$$->childs.push_back($1);
			$$->paramList.push_back($1);
		}
	| Defn_Param									
		{
			$$ = new Node("decl_plist", "defn_type_one");
			$$->childs.push_back($1);
			$$->paramList.push_back($1);
		}
;

Func_Call:
	ID OPEN_PAR Param_List CLOSE_PAR				
		{
			$$ = new Node("func_call", "");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
;

Param_List:
	Expression COMMA Param_List				
		{
			$$ = new Node("pm_list", "more");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Expression							
		{
			$$ = new Node("pm_list", "one");
			$$->childs.push_back($1);

		}
;

Func_Defn:
	Func_Decl Block						
		{
			$$ = new Node("func_defn", "");
			$$->childs.push_back($1);
			$$->childs.push_back($2);

		}
;

Decl_Param:
	INT									
		{
			$$ = new Node("decl_pm", "int");
		}
	| FLOAT								
		{
			$$ = new Node("decl_pm", "flt");
		}
;

Defn_Param:
	INT ID								
		{
			$$ = new Node("defn_pm", "int");
			$$->childs.push_back($2);
		}
	| FLOAT ID							
		{
			$$ = new Node("defn_pm", "flt");
			$$->childs.push_back($2);
		}
;

Statements:
	Statement Statements				
		{
			$$ = new Node("statements", "more");
			$$->childs.push_back($1);
			$$->childs.push_back($2);

		}
	| Statement							
		{
			$$ = new Node("statements", "one");
			$$->childs.push_back($1);

		}
;

Statement:
	Non_Conditional_Statement				
		{
			$$ = new Node("statement", "non_condl");
			$$->childs.push_back($1);

		}
	| Conditional_Block						
		{
			$$ = new Node("statement", "condl");
			$$->childs.push_back($1);

		}
;

Non_Conditional_Statement:
	Block									
		{
			$$ = new Node("non_condl", "block");
			$$->childs.push_back($1);

		}
	| Loop_Block							
		{
			$$ = new Node("non_condl", "loop");
			$$->childs.push_back($1);

		}
	| Var_Decl								
		{
			$$ = new Node("non_condl", "var_decl");
			$$->childs.push_back($1);

		}
	| Expression SEMI						
		{
			$$ = new Node("non_condl", "expr_stmt");
			$$->childs.push_back($1);

		}
	| BREAK SEMI							
		{
			$$ = new Node("non_condl", "brk_stmt");

		}
	| CONTINUE SEMI							
		{
			$$ = new Node("non_condl", "cont_stmt");

		}
	| RETURN Expression SEMI				
		{
			$$ = new Node("non_condl", "ret_stmt");
			$$->childs.push_back($2);

		}
	| SEMI									
		{
			$$ = new Node("non_condl", "semi");

		}
;

Block:
	OPEN_CURLY Statements CLOSE_CURLY							
		{
			$$ = new Node("block", "");
			$$->childs.push_back($2);

		}
;

Loop_Block:
	FOR OPEN_PAR For_Control CLOSE_PAR Statement				
		{
			$$ = new Node("loop", "for");
			$$->childs.push_back($3);
			$$->childs.push_back($5);

		}
	| WHILE OPEN_PAR Condition CLOSE_PAR Statement				
		{
			$$ = new Node("loop", "condl");
			$$->childs.push_back($3);
			$$->childs.push_back($5);

		}
;

For_Control:
	Init_Statement Condition SEMI Expression					
		{
			$$ = new Node("for", "condl");
			$$->childs.push_back($1);
			$$->childs.push_back($2);
			$$->childs.push_back($4);

		}
	| Init_Statement SEMI Expression							
		{
			$$ = new Node("for", "none");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
;

Init_Statement:
	Expression SEMI					
		{
			$$ = new Node("init_stmt", "expr");
			$$->childs.push_back($1);

		}
	| SEMI							
		{
			$$ = new Node("init_stmt", "semi");

		}
;

Conditional_Block:
	If_Else_Block					
		{
			$$ = new Node("condl_block", "if_else");
			$$->childs.push_back($1);

		}
	| Switch_Block					
		{
			$$ = new Node("condl_block", "switch");
			$$->childs.push_back($1);

		}
;

If_Else_Block:
	IF OPEN_PAR Condition CLOSE_PAR Statement %prec THEN				
		{
			$$ = new Node("if_else", "if");
			$$->childs.push_back($3);
			$$->childs.push_back($5);

		}
	| IF OPEN_PAR Condition CLOSE_PAR Statement ELSE Statement			
		{
			$$ = new Node("if_else", "if_else");
			$$->childs.push_back($3);
			$$->childs.push_back($5);
			$$->childs.push_back($7);

		}
;

Switch_Block:
	SWITCH OPEN_PAR Constant_Expression CLOSE_PAR OPEN_CURLY Switch_Body CLOSE_CURLY				
		{
			$$ = new Node("switch", "const");
			$$->childs.push_back($3);
			$$->childs.push_back($6);

		}
	| SWITCH OPEN_PAR Var CLOSE_PAR OPEN_CURLY Switch_Body CLOSE_CURLY								
		{
			$$ = new Node("switch", "var");
			$$->childs.push_back($3);
			$$->childs.push_back($6);

		}
;

Switch_Body:
	CASE Constant_Expression COLON Statements		
		{
			$$ = new Node("switch_body", "case");
			$$->childs.push_back($2);
			$$->childs.push_back($4);

		}
	| DEFAULT COLON Statements						
		{
			$$ = new Node("switch_body", "deafult");
			$$->childs.push_back($3);

		}
;

Condition:
	OPEN_PAR Condition CLOSE_PAR			
		{
			$$ = new Node("condition", "par_cond");
			$$->childs.push_back($2);

		}
	| NOT Condition							
		{
			$$ = new Node("condition", "not_cond");
			$$->childs.push_back($2);

		}
	| Condition OR Condition				
		{
			$$ = new Node("condition", "or");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Condition AND Condition				
		{
			$$ = new Node("condition", "and");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Expression LT Expression				
		{
			$$ = new Node("condition", "lt");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Expression GT Expression				
		{
			$$ = new Node("condition", "gt");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Expression LTE Expression				
		{
			$$ = new Node("condition", "lte");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Expression GTE Expression				
		{
			$$ = new Node("condition", "gte");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Expression EQ Expression				
		{
			$$ = new Node("condition", "eq");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Expression NEQ Expression				
		{
			$$ = new Node("condition", "neq");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
;

Constant_Expression:
	REAL																
		{
			$$ = new Node("const_expr", "real");
			$$->childs.push_back($1);

		}
	| OPEN_PAR Constant_Expression CLOSE_PAR							
		{
			$$ = new Node("const_expr", "par_exp");
			$$->childs.push_back($2);
			 }

	| Constant_Expression PLUS Constant_Expression						
		{
			$$ = new Node("const_expr", "plus");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Constant_Expression MINUS Constant_Expression						
		{
			$$ = new Node("const_expr", "minus");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Constant_Expression TIMES Constant_Expression						
		{
			$$ = new Node("const_expr", "times");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Constant_Expression DIVIDE Constant_Expression					
		{
			$$ = new Node("const_expr", "divide");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Constant_Expression MODULO Constant_Expression					
		{
			$$ = new Node("const_expr", "modulo");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| MINUS Constant_Expression %prec NEG								
		{
			$$ = new Node("const_expr", "neg");
			$$->childs.push_back($2);

		}
;

Expression:
	REAL											
		{
			$$ = new Node("expr", "real");
			$$->childs.push_back($1);
			$$->nodeVal = stof($1->valueType);

		}
	| Var											
		{
			$$ = new Node("expr", "var");
			$$->childs.push_back($1);

		}
	| Var_Asgn										
		{
			$$ = new Node("expr", "val_asgn");
			$$->childs.push_back($1);

		}
	| Func_Call										
		{
			$$ = new Node("expr", "func_call");
			$$->childs.push_back($1);

		}
	| Var INCREMENT									
		{
			$$ = new Node("expr", "var_incr");
			$$->childs.push_back($1);

		}
	| Var DECREMENT									
		{
			$$ = new Node("expr", "var_decr");
			$$->childs.push_back($1);

		}
	| INCREMENT Var									
		{
			$$ = new Node("expr", "incr_var");
			$$->childs.push_back($2);

		}
	| DECREMENT Var									
		{
			$$ = new Node("expr", "decr_var");
			$$->childs.push_back($2);

		}
	| OPEN_PAR Expression CLOSE_PAR					
		{
			$$ = new Node("expr", "par_exp");
			$$->childs.push_back($2);

		}
	| Expression PLUS Expression					
		{
			$$ = new Node("expr", "plus");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Expression MINUS Expression					
		{
			$$ = new Node("expr", "minus");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Expression TIMES Expression					
		{
			$$ = new Node("expr", "times");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Expression DIVIDE Expression					
		{
			$$ = new Node("expr", "divide");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| Expression MODULO Expression					
		{
			$$ = new Node("expr", "modulo");
			$$->childs.push_back($1);
			$$->childs.push_back($3);

		}
	| MINUS Expression %prec NEG					
		{
			$$ = new Node("expr", "neg");
			$$->childs.push_back($2);

		}
;

%%

void yyerror(string s){
	cout<<"Syntax Error in:\nLine Number " << yylineno <<" : "<<s<<endl;
	syntax_error = true;
}

int main(int argc, char *argv[]){
	bool semantic_check = false; 
	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);
}