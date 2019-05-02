%{
#include <bits/stdc++.h>
#include "compiler.h"
using namespace std;

extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(string s);
bool syntax_error = false;
DataType declType = dt_none;
int level;
Node* parseTree = new Node("parse_tree","");
vector <FuncNode*> funcTable;
vector <SymbolNode*> globalVars;

FuncNode* activeFuncPtr;

extern int yylineno;

FuncNode* functionFinder(string name){
	for (int i=0; i<funcTable.size(); i++){
		if (funcTable[i]->name == name){
			return funcTable[i];
		}
	}
	return NULL;
}

SymbolNode* paramExists(vector <SymbolNode*> &paramList, string name){
	for (int i=0; i<paramList.size(); i++){
		if (paramList[i]->name == name){
			return paramList[i];
		}
	}
	return NULL;
}

int convertParamList(vector <Node*> &nodeList ,vector <SymbolNode*> &paramList, string funcName){
	int retValue = 0;
	for (int i=nodeList.size()-1; i>=0; i--){
		if (nodeList[i]->dataType == "decl_pm"){
			if(nodeList[i]->valueType == "int"){
				paramList.push_back(new SymbolNode("",false,1,dt_int));
			}
			else if(nodeList[i]->valueType == "flt"){
				paramList.push_back(new SymbolNode("",false,1,dt_flt));
			}
		}
		else if(nodeList[i]->dataType == "defn_pm"){
			if (paramExists(paramList, nodeList[i]->childs[0]->valueType)==NULL){
				if(nodeList[i]->valueType == "int"){
					paramList.push_back(new SymbolNode(nodeList[i]->childs[0]->valueType,false,1,dt_int));
				}
				else if(nodeList[i]->valueType == "flt"){
					paramList.push_back(new SymbolNode(nodeList[i]->childs[0]->valueType,false,1,dt_flt));
				}
			}
			else{
				cout << "Parameter "<<nodeList[i]->childs[0]->valueType<<" defined again in function: "<<funcName<<endl;
				retValue = -1;
			}
		}
	}
	return retValue;
}

SymbolNode *varExists(string name){
	if (functionFinder(name)!=NULL){
		return new SymbolNode(name, false, 0, dt_void);
	}
	if (activeFuncPtr!=NULL){
		for (int i=activeFuncPtr->localVar.size()-1; i>=0; i--){
			if (activeFuncPtr->localVar[i]->name == name){
				return activeFuncPtr->localVar[i];
			}
		}
	}
	for (int i=0; i<globalVars.size(); i++){
		if (globalVars[i]->name == name){
			return globalVars[i];
		}
	}
	return NULL;
}

void addVariable(string name){
	if (activeFuncPtr==NULL){
		globalVars.push_back(new SymbolNode(name, false, 1, declType));
	}
	else{
		activeFuncPtr->localVar.push_back(new SymbolNode(name, false, level, declType));
	}
}

void clearLevel(){
	if (activeFuncPtr!=NULL){
		for (int i=activeFuncPtr->localVar.size()-1; i>=0; i--){
			if (activeFuncPtr->localVar[i]->level == level){
				activeFuncPtr->localVar.pop_back();
			}
			else{
				break;
			}
		}
	}
}

bool isNumber(string s){
	try{
		stoi(s);
	}
	catch(exception e){
		return false;
	}
	return true;
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
%token INT FLOAT VOID RETURN
%token <node> REAL ID
%token ERROR END 

%type <node> Var_Decl Var_List Var Var_Asgn Dim_List Brac_Dim_List
%type <node> Func_Decl Decl_Param_List Func_Call Param_List Func_Defn Decl_Param Defn_Param 
%type <node> Statements Statement Non_Conditional_Statement Block Loop_Block For_Control Init_Statement 
%type <node> Conditional_Block If_Else_Block Switch_Block Switch_Body Condition Constant_Expression Expression

%right ASGN
%right AND OR
%right ELSE THEN
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
	Var_Decl				
		{ 
			parseTree->childs.push_back($1);
		}
	| Func_Decl SEMI		
		{
			if ($1->elemType != dt_err){
				FuncNode *funcExists = functionFinder(activeFuncPtr->name);
				if (funcExists == NULL){
					for (int i=0; i<activeFuncPtr->paramList.size(); i++){
						activeFuncPtr->paramList[i]->name = "";
					}
					funcTable.push_back(activeFuncPtr);
				}
				else{
					cout << "Duplicate declaration for function : "<< activeFuncPtr->name << endl;
					$1->elemType = dt_err;
				}
			}
			parseTree->childs.push_back($1);
		}
	| Func_Defn				
		{ 
			parseTree->childs.push_back($1);
		}
;

Var_Decl:
	INT Data_Type_Int Var_List SEMI Data_Type_None				
		{
			$$ = new Node("var_decl", "int");
			$$->childs.push_back($3);

		}
	| FLOAT Data_Type_Flt Var_List SEMI Data_Type_None			
		{
			$$ = new Node("var_decl", "flt");
			$$->childs.push_back($3);

		}
;

Data_Type_Flt:
	{declType = dt_flt;}
;
Data_Type_Int:
	{declType = dt_int;}
;
Data_Type_None:
	{declType = dt_none;}
;

Var_List:
	Var COMMA Var_List					
		{
			$$ = new Node("var_list", "var_more");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($3->elemType != dt_err){
				SymbolNode *temp = varExists($1->childs[0]->valueType);
				if (temp==NULL){
					addVariable($1->childs[0]->valueType);
				}
				else{
					if (temp->level == 1 && level==2){
						$$->elemType = dt_err;
						cout << "Declaration of variable with same name as parameter: "<<$1->childs[0]->valueType<<endl;
					}
					else if (temp->level != level || temp->type != dt_void){
						addVariable($1->childs[0]->valueType);
					}
					else{
						$$->elemType = dt_err;
						cout << "Duplicate declaration of variable: "<<$1->childs[0]->valueType<<endl;
					}
				}
			}
			else{
				$$->elemType = dt_err;
			}
		}
	| Var_Asgn COMMA Var_List			
		{
			$$ = new Node("var_list", "var_asgn_more");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($3->elemType != dt_err){
				SymbolNode *temp = varExists($1->childs[0]->childs[0]->valueType);
				if (temp==NULL){
					if (temp->level == 1 && level==2){
						$$->elemType = dt_err;
						cout << "Declaration of variable with same name as parameter: "<<$1->childs[0]->childs[0]->valueType<<endl;
					}
					else if ($1->childs[1]->elemType != dt_err){
						addVariable($1->childs[0]->childs[0]->valueType);
					}
					else{
						$$->elemType = dt_err;
					}
				}
				else{
					if (temp->level != level && temp->type != dt_void){
						addVariable($1->childs[0]->childs[0]->valueType);
					}
					else{
						$$->elemType = dt_err;
						cout << "Duplicate declaration of variable: "<<$1->childs[0]->childs[0]->valueType<<endl;
					}
				}
			}
			else{
				$$->elemType = dt_err;
			}
		}
	| Var								
		{
			$$ = new Node("var_list", "var");
			$$->childs.push_back($1);
			if ($1->elemType != dt_err){
				SymbolNode *temp = varExists($1->childs[0]->valueType);
				if (temp==NULL){
					addVariable($1->childs[0]->valueType);
				}
				else{
					if (temp->level == 1 && level==2){
						$$->elemType = dt_err;
						cout << "Declaration of variable with same name as parameter: "<<$1->childs[0]->valueType<<endl;
					}
					else if (temp->level != level || temp->type != dt_void){
						addVariable($1->childs[0]->valueType);
					}
					else{
						$$->elemType = dt_err;
						cout << "Duplicate declaration of variable: "<<$1->childs[0]->valueType<<endl;
					}
				}
			}
			else{
				$$->elemType = dt_err;
			}
		}
	| Var_Asgn							
		{
			$$ = new Node("var_list", "var_asgn");
			$$->childs.push_back($1);
			if ($1->childs[0]->elemType != dt_err){
				SymbolNode *temp = varExists($1->childs[0]->childs[0]->valueType);
				if (temp==NULL){
					if ($1->childs[1]->elemType != dt_err){
						addVariable($1->childs[0]->childs[0]->valueType);
					}
					else{
						$$->elemType = dt_err;
					}
				}
				else{
					if (temp->level == 1 && level==2){
						$$->elemType = dt_err;
						cout << "Declaration of variable with same name as parameter: "<<$1->childs[0]->childs[0]->valueType<<endl;
					}
					else if (temp->level != level && temp->type != dt_void){
						addVariable($1->childs[0]->childs[0]->valueType);
					}
					else{
						$$->elemType = dt_err;
						cout << "Duplicate declaration of variable: "<<$1->childs[0]->childs[0]->valueType<<endl;
					}
				}
			}
			else{
				$$->elemType = dt_err;
			}
		}
;

Var:
	ID															
		{
			$$ = new Node("var", "id");
			$$->childs.push_back($1);
		}
	| ID OPEN_BRAC Expression COMMA Dim_List CLOSE_BRAC			
		{
			$$ = new Node("var", "id_dim_list");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			$$->childs.push_back($5);
			$$->elemType = dt_err;
			cout << "Arrays not implemented" << endl;
		}
	| ID Brac_Dim_List											
		{
			$$ = new Node("var", "id_brac");
			$$->childs.push_back($1);
			$$->childs.push_back($2);
			$$->elemType = dt_err;
			cout << "Arrays not implemented" << endl;
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
	INT Data_Type_Int ID Data_Type_None OPEN_PAR Decl_Param_List CLOSE_PAR					
		{
			level = 1;
			$$ = new Node("func_decl", "int_plist");
			$$->childs.push_back($6);
			$$->paramList = $6->paramList;
			vector <SymbolNode*> paramList;
			if (convertParamList($$->paramList, paramList, $3->valueType)==0){
				FuncNode *funcEntry = new FuncNode($3->valueType, dt_int);
				funcEntry->paramList = paramList;
				funcEntry->localVar = paramList;
				activeFuncPtr = funcEntry;
			}
			else{
				$$->elemType = dt_err;
			}
		}
	| FLOAT Data_Type_Flt ID Data_Type_None OPEN_PAR Decl_Param_List CLOSE_PAR				
		{
			$$ = new Node("func_decl", "float_plist");
			$$->childs.push_back($6);
			$$->paramList = $6->paramList;
			vector <SymbolNode*> paramList;
			if (convertParamList($$->paramList, paramList, $3->valueType)==0){
				FuncNode *funcEntry = new FuncNode($3->valueType, dt_flt);
				funcEntry->paramList = paramList;
				funcEntry->localVar = paramList;
				activeFuncPtr = funcEntry;
			}
			else{
				$$->elemType = dt_err;
			}
		}
	| VOID ID OPEN_PAR Decl_Param_List CLOSE_PAR				
		{
			$$ = new Node("func_decl", "void_plist");
			$$->childs.push_back($4);
			$$->paramList = $4->paramList;
			vector <SymbolNode*> paramList;
			if (convertParamList($$->paramList, paramList, $2->valueType)==0){
				FuncNode *funcEntry = new FuncNode($2->valueType, dt_void);
				funcEntry->paramList = paramList;
				funcEntry->localVar = paramList;
				activeFuncPtr = funcEntry;
			}
			else{
				$$->elemType = dt_err;
			}
		}
	| INT Data_Type_Int ID Data_Type_None OPEN_PAR CLOSE_PAR									
		{
			$$ = new Node("func_decl", "int_none");
			FuncNode *funcEntry = new FuncNode($3->valueType, dt_int);
			activeFuncPtr = funcEntry;
		}
	| FLOAT Data_Type_Flt ID Data_Type_None OPEN_PAR CLOSE_PAR								
		{
			$$ = new Node("func_decl", "float_none");
			FuncNode *funcEntry = new FuncNode($3->valueType, dt_flt);
			activeFuncPtr = funcEntry;
		}
	| VOID ID OPEN_PAR CLOSE_PAR								
		{
			$$ = new Node("func_decl", "void_none");
			FuncNode *funcEntry = new FuncNode($2->valueType, dt_void);
			activeFuncPtr = funcEntry;
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
			int defnParams = -1;
			for (int i=0; i<activeFuncPtr->paramList.size(); i++){
				if (activeFuncPtr->paramList[i]->name==""){
					defnParams = i;
					break;
				}
			}
			if (defnParams == -1){
				if ($2->elemType == dt_err){
					$$->elemType = dt_err;
				}
				else{
					
				}
			}
			else{
				cout << "Error in function definition, parameter has no name" << endl;
				$$->elemType = dt_err;
			}

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
			if ($1->elemType == dt_err || $2->elemType == dt_err){
				$$->elemType = dt_err;
			}
		}
	| Statement							
		{
			$$ = new Node("statements", "one");
			$$->childs.push_back($1);
			if ($1->elemType == dt_err){
				$$->elemType = dt_err;
			}
		}
;

Statement:
	Non_Conditional_Statement				
		{
			$$ = new Node("statement", "non_condl");
			$$->childs.push_back($1);
			if ($1->elemType == dt_err){
				$$->elemType = dt_err;
			}
		}
	| Conditional_Block						
		{
			$$ = new Node("statement", "condl");
			$$->childs.push_back($1);
			if ($1->elemType == dt_err){
				$$->elemType = dt_err;
			}
		}
;

Non_Conditional_Statement:
	Block									
		{
			$$ = new Node("non_condl", "block");
			$$->childs.push_back($1);
			if ($1->elemType == dt_err){
				$$->elemType = dt_err;
			}
		}
	| Loop_Block							
		{
			$$ = new Node("non_condl", "loop");
			$$->childs.push_back($1);
			if ($1->elemType == dt_err){
				$$->elemType = dt_err;
			}
		}
	| Var_Decl								
		{
			$$ = new Node("non_condl", "var_decl");
			$$->childs.push_back($1);
			if ($1->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else{

			}
		}
	| Expression SEMI						
		{
			$$ = new Node("non_condl", "expr_stmt");
			$$->childs.push_back($1);
			if ($1->elemType == dt_err){
				$$->elemType = dt_err;
			}
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
			if ($2->elemType != activeFuncPtr->retType){
				$$->elemType = dt_err;
			}
		}
	| SEMI									
		{
			$$ = new Node("non_condl", "semi");

		}
;

Block:
	OPEN_CURLY Level_PP Statements Clear_Level Level_MM CLOSE_CURLY							
		{
			$$ = new Node("block", "");
			$$->childs.push_back($3);
			if ($3->elemType == dt_err){
				$$->elemType = dt_err;
			}
		}
;

Loop_Block:
	FOR OPEN_PAR For_Control CLOSE_PAR Level_PP Statement Clear_Level Level_MM
		{
			$$ = new Node("loop", "for");
			$$->childs.push_back($3);
			$$->childs.push_back($6);
			if ($3->elemType == dt_err || $6->elemType == dt_err){
				$$->elemType = dt_err;
			}
		}
	| WHILE OPEN_PAR Condition CLOSE_PAR Level_PP Statement Clear_Level Level_MM			
		{
			$$ = new Node("loop", "condl");
			$$->childs.push_back($3);
			$$->childs.push_back($6);
			if ($3->elemType == dt_err || $6->elemType == dt_err){
				$$->elemType = dt_err;
			}
		}
;

For_Control:
	Init_Statement Condition SEMI Expression					
		{
			$$ = new Node("for", "condl");
			$$->childs.push_back($1);
			$$->childs.push_back($2);
			$$->childs.push_back($4);
			if ($1->elemType == dt_err || $2->elemType != dt_bool || $4->elemType == dt_err){
				$$->elemType = dt_err;
			}
		}
	| Init_Statement SEMI Expression							
		{
			$$ = new Node("for", "none");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
		}
;

Init_Statement:
	Expression SEMI					
		{
			$$ = new Node("init_stmt", "expr");
			$$->childs.push_back($1);
			if ($1->elemType == dt_err){
				$$->elemType = dt_err;
			}
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
			$$->elemType = $1->elemType;
		}
	| Switch_Block					
		{
			$$ = new Node("condl_block", "switch");
			$$->childs.push_back($1);
			$$->elemType = $1->elemType;
		}
;

If_Else_Block:
	IF OPEN_PAR Condition CLOSE_PAR Level_PP Statement Clear_Level Level_MM %prec THEN				
		{
			$$ = new Node("if_else", "if");
			$$->childs.push_back($3);
			$$->childs.push_back($6);
			if ($3->elemType != dt_bool || $6->elemType == dt_err){
				$$->elemType = dt_err;
			}
		}
	| IF OPEN_PAR Condition CLOSE_PAR Level_PP Statement Clear_Level Level_MM ELSE Level_PP Statement Clear_Level Level_MM
		{
			$$ = new Node("if_else", "if_else");
			$$->childs.push_back($3);
			$$->childs.push_back($6);
			$$->childs.push_back($11);
			if ($3->elemType != dt_bool || $6->elemType == dt_err || $11->elemType == dt_err){
				$$->elemType = dt_err;
			}
		}
;

Switch_Block:
	SWITCH OPEN_PAR Constant_Expression CLOSE_PAR OPEN_CURLY Switch_Body CLOSE_CURLY				
		{
			$$ = new Node("switch", "const");
			$$->childs.push_back($3);
			$$->childs.push_back($6);
			if ($3->elemType == dt_int && $6->elemType != dt_err){
				
			}
			else{
				$$->elemType = dt_err;
			}
		}
	| SWITCH OPEN_PAR Var CLOSE_PAR OPEN_CURLY Switch_Body CLOSE_CURLY								
		{
			$$ = new Node("switch", "var");
			$$->childs.push_back($3);
			$$->childs.push_back($6);
			if ($3->valueType == "id"){
				SymbolNode *temp=varExists($3->childs[0]->valueType);
				if ($3->elemType == dt_int && $6->elemType != dt_err && temp!=NULL){
					
				}
				else{
					$$->elemType = dt_err;
				}
			}
			else{
				$$->elemType = dt_err;
			}
		}
;

Switch_Body:
	CASE Constant_Expression COLON Level_PP Statements Clear_Level Level_MM Switch_Body
		{
			$$ = new Node("switch_body", "case_more");
			$$->childs.push_back($2);
			$$->childs.push_back($5);
			$$->childs.push_back($8);
			if ($2->elemType == dt_int && $5->elemType != dt_err && $8->elemType != dt_err){
				
			}
			else{
				$$->elemType = dt_err;
			}
			
		}
	| DEFAULT COLON Level_PP Statements Clear_Level Level_MM Switch_Body
		{
			$$ = new Node("switch_body", "deafult_more");
			$$->childs.push_back($4);
			$$->childs.push_back($7);
			if ($4->elemType != dt_err && $7->elemType != dt_err){
				
			}
			else{
				$$->elemType = dt_err;
			}
		}
	| CASE Constant_Expression COLON Level_PP Statements Clear_Level Level_MM
		{
			$$ = new Node("switch_body", "case_one");
			$$->childs.push_back($2);
			$$->childs.push_back($5);
			if ($2->elemType == dt_int && $5->elemType != dt_err){
				
			}
			else{
				$$->elemType = dt_err;
			}
			
		}
	| DEFAULT COLON Level_PP Statements Clear_Level Level_MM
		{
			$$ = new Node("switch_body", "deafult_one");
			$$->childs.push_back($4);
			if ($4->elemType != dt_err){
				
			}
			else{
				$$->elemType = dt_err;
			}
		}
;

Condition:
	OPEN_PAR Condition CLOSE_PAR			
		{
			$$ = new Node("condition", "par_cond");
			$$->childs.push_back($2);
			if ($2->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else{
				$$->elemType = dt_bool;
			}
		}
	| NOT Condition							
		{
			$$ = new Node("condition", "not_cond");
			$$->childs.push_back($2);
			if ($2->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else{
				$$->elemType = dt_bool;
			}
		}
	| Condition OR Condition				
		{
			$$ = new Node("condition", "or");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else{
				$$->elemType = dt_bool;
			}
		}
	| Condition AND Condition				
		{
			$$ = new Node("condition", "and");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else{
				$$->elemType = dt_bool;
			}
		}
	| Expression LT Expression				
		{
			$$ = new Node("condition", "lt");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_void || $3->elemType == dt_void){
				$$->elemType = dt_err;
				cout << "Incompatible types for < operation"<<endl;
			}
			else{
				$$->elemType = dt_bool;
			}
		}
	| Expression GT Expression				
		{
			$$ = new Node("condition", "gt");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_void || $3->elemType == dt_void){
				$$->elemType = dt_err;
				cout << "Incompatible types for > operation"<<endl;
			}
			else{
				$$->elemType = dt_bool;
			}
		}
	| Expression LTE Expression				
		{
			$$ = new Node("condition", "lte");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_void || $3->elemType == dt_void){
				$$->elemType = dt_err;
				cout << "Incompatible types for <= operation"<<endl;
			}
			else{
				$$->elemType = dt_bool;
			}
		}
	| Expression GTE Expression				
		{
			$$ = new Node("condition", "gte");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_void || $3->elemType == dt_void){
				$$->elemType = dt_err;
				cout << "Incompatible types for >= operation"<<endl;
			}
			else{
				$$->elemType = dt_bool;
			}
		}
	| Expression EQ Expression				
		{
			$$ = new Node("condition", "eq");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_void || $3->elemType == dt_void){
				$$->elemType = dt_err;
				cout << "Incompatible types for == operation"<<endl;
			}
			else{
				$$->elemType = dt_bool;
			}
		}
	| Expression NEQ Expression				
		{
			$$ = new Node("condition", "neq");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_void || $3->elemType == dt_void){
				$$->elemType = dt_err;
				cout << "Incompatible types for != operation"<<endl;
			}
			else{
				$$->elemType = dt_bool;
			}
		}
;

Constant_Expression:
	REAL																
		{
			$$ = new Node("const_expr", "real");
			$$->childs.push_back($1);
			if (isNumber($1->valueType)){
				$$->elemType = dt_int;
				$$->nodeValInt = stoi($1->valueType);
			}
			else{
				$$->elemType = dt_flt;
				$$->nodeVal = stof($1->valueType);
			}
		}
	| OPEN_PAR Constant_Expression CLOSE_PAR							
		{
			$$ = new Node("const_expr", "par_exp");
			$$->childs.push_back($2);
			$$->elemType = $2->elemType;
		}

	| Constant_Expression PLUS Constant_Expression						
		{
			$$ = new Node("const_expr", "plus");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_flt || $3->elemType == dt_flt){
				$$->elemType = dt_flt;
			}
			else{
				$$->elemType = dt_int;
			}
		}
	| Constant_Expression MINUS Constant_Expression						
		{
			$$ = new Node("const_expr", "minus");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_flt || $3->elemType == dt_flt){
				$$->elemType = dt_flt;
			}
			else{
				$$->elemType = dt_int;
			}
		}
	| Constant_Expression TIMES Constant_Expression						
		{
			$$ = new Node("const_expr", "times");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_flt || $3->elemType == dt_flt){
				$$->elemType = dt_flt;
			}
			else{
				$$->elemType = dt_int;
			}
		}
	| Constant_Expression DIVIDE Constant_Expression					
		{
			$$ = new Node("const_expr", "divide");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_flt || $3->elemType == dt_flt){
				$$->elemType = dt_flt;
			}
			else{
				$$->elemType = dt_int;
			}
		}
	| Constant_Expression MODULO Constant_Expression					
		{
			$$ = new Node("const_expr", "modulo");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_flt || $3->elemType == dt_flt){
				$$->elemType = dt_err;
				cout << "Incompatible types for %% operation"<<endl;
			}
			else{
				$$->elemType = dt_int;
			}
		}
	| MINUS Constant_Expression %prec NEG								
		{
			$$ = new Node("const_expr", "neg");
			$$->childs.push_back($2);
			$$->elemType = $2->elemType;
		}
;

Expression:
	REAL											
		{
			$$ = new Node("expr", "real");
			$$->childs.push_back($1);
			if (isNumber($1->valueType)){
				$$->elemType = dt_int;
				$$->nodeValInt = stoi($1->valueType);
			}
			else{
				$$->elemType = dt_flt;
				$$->nodeVal = stof($1->valueType);
			}
		}
	| Var											
		{
			$$ = new Node("expr", "var");
			$$->childs.push_back($1);
			if ($1->elemType != dt_err){
				SymbolNode *temp = varExists($1->childs[0]->valueType);
				if (temp!=NULL){
					$$->elemType = temp->type;
				}
				else{
					$$->elemType = dt_err;
					cout << "Variable "<< $1->childs[0]->valueType << " used without declaration"<<endl;
				}
			}
			else{
				$$->elemType = dt_err;
			}
		}
	| Var_Asgn										
		{
			$$ = new Node("expr", "val_asgn");
			$$->childs.push_back($1);
			if ($1->childs[0]->elemType != dt_err){
				SymbolNode *temp = varExists($1->childs[0]->childs[0]->valueType);
				if (temp != NULL){
					DataType exprType = $1->childs[1]->childs[0]->elemType;
					if (exprType == dt_err){
						$$->elemType = dt_err;
					}
					else{
						$$->elemType = temp->type;
					}
				}
				else{
					$$->elemType = dt_err;
					cout << "Variable "<< $1->childs[0]->childs[0]->valueType << " used without declaration"<<endl;
				}
			}
		}
	| Func_Call										
		{
			$$ = new Node("expr", "func_call");
			$$->childs.push_back($1);
			$$->elemType = $1->elemType;
		}
	| Var INCREMENT									
		{
			$$ = new Node("expr", "var_incr");
			$$->childs.push_back($1);
			SymbolNode *temp;
			if ($1->valueType == "id"){
				temp=varExists($1->childs[0]->valueType);
				if (temp!=NULL){
					$$->elemType = temp->type;
				}
				else{
					$$->elemType = dt_err;
					cout << "Variable "<< $1->childs[0]->valueType << " used without declaration"<<endl;
				}
			}
			else{
				$$->elemType = dt_err;
			}
		}
	| Var DECREMENT									
		{
			$$ = new Node("expr", "var_decr");
			$$->childs.push_back($1);
			SymbolNode *temp;
			if ($1->valueType == "id"){
				temp=varExists($1->childs[0]->valueType);
				if (temp!=NULL){
					$$->elemType = temp->type;
				}
				else{
					$$->elemType = dt_err;
					cout << "Variable "<< $1->childs[0]->valueType << " used without declaration"<<endl;
				}
			}
			else{
				$$->elemType = dt_err;
			}
		}
	| INCREMENT Var									
		{
			$$ = new Node("expr", "incr_var");
			$$->childs.push_back($2);
			SymbolNode *temp;
			if ($2->valueType == "id"){
				temp=varExists($2->childs[0]->valueType);
				if (temp!=NULL){
					$$->elemType = temp->type;
				}
				else{
					$$->elemType = dt_err;
					cout << "Variable "<< $2->childs[0]->valueType << " used without declaration"<<endl;
				}
			}
			else{
				$$->elemType = dt_err;
			}
		}
	| DECREMENT Var									
		{
			$$ = new Node("expr", "decr_var");
			$$->childs.push_back($2);
			SymbolNode *temp;
			if ($2->valueType == "id"){
				temp=varExists($2->childs[0]->valueType);
				if (temp!=NULL){
					$$->elemType = temp->type;
				}
				else{
					$$->elemType = dt_err;
					cout << "Variable "<< $2->childs[0]->valueType << " used without declaration"<<endl;
				}
			}
			else{
				$$->elemType = dt_err;
			}
		}
	| OPEN_PAR Expression CLOSE_PAR					
		{
			$$ = new Node("expr", "par_exp");
			$$->childs.push_back($2);
			$$->elemType = $2->elemType;
		}
	| Expression PLUS Expression					
		{
			$$ = new Node("expr", "plus");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_flt || $3->elemType == dt_flt){
				$$->elemType = dt_flt;
			}
			else if($1->elemType == dt_void || $3->elemType == dt_void){
				$$->elemType = dt_err;
				cout << "Incompatible types for + operation"<<endl;
			}
			else{
				$$->elemType = dt_int;
			}
		}
	| Expression MINUS Expression					
		{
			$$ = new Node("expr", "minus");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_flt || $3->elemType == dt_flt){
				$$->elemType = dt_flt;
			}
			else if($1->elemType == dt_void || $3->elemType == dt_void){
				$$->elemType = dt_err;
				cout << "Incompatible types for - operation"<<endl;
			}
			else{
				$$->elemType = dt_int;
			}
		}
	| Expression TIMES Expression					
		{
			$$ = new Node("expr", "times");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_flt || $3->elemType == dt_flt){
				$$->elemType = dt_flt;
			}
			else if($1->elemType == dt_void || $3->elemType == dt_void){
				$$->elemType = dt_err;
				cout << "Incompatible types for * operation"<<endl;
			}
			else{
				$$->elemType = dt_int;
			}
		}
	| Expression DIVIDE Expression					
		{
			$$ = new Node("expr", "divide");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_flt || $3->elemType == dt_flt){
				$$->elemType = dt_flt;
			}
			else if($1->elemType == dt_void || $3->elemType == dt_void){
				$$->elemType = dt_err;
				cout << "Incompatible types for / operation"<<endl;
			}
			else{
				$$->elemType = dt_int;
			}
		}
	| Expression MODULO Expression					
		{
			$$ = new Node("expr", "modulo");
			$$->childs.push_back($1);
			$$->childs.push_back($3);
			if ($1->elemType == dt_err || $3->elemType == dt_err){
				$$->elemType = dt_err;
			}
			else if($1->elemType == dt_flt || $3->elemType == dt_flt){
				$$->elemType = dt_err;
				cout << "Incompatible types for %% operation"<<endl;
			}
			else if($1->elemType == dt_void || $3->elemType == dt_void){
				$$->elemType = dt_err;
				cout << "Incompatible types for %% operation"<<endl;
			}
			else{
				$$->elemType = dt_int;
			}
		}
	| MINUS Expression %prec NEG					
		{
			$$ = new Node("expr", "neg");
			$$->childs.push_back($2);
			if($2->elemType == dt_void){
				$$->elemType = dt_err;
				cout << "Incompatible types for - operation"<<endl;
			}
			else{
				$$->elemType = $2->elemType;
			}
		}
;

Level_PP:
	{level++;}
;

Level_MM:
	{level--;}
;

Clear_Level:
	{clearLevel();}
;
%%

void yyerror(string s){
	cout<<"Syntax Error in:\nLine Number " << yylineno <<" : "<<s<<endl;
	syntax_error = true;
}

int main(int argc, char *argv[]){
	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);
	cout << "***********";
	printTree(parseTree);
	return 0;
}