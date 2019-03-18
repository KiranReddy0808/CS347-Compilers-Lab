%option noyywrap
%option stack

%x C_COMMENT
%x STRING

%x CLASS
%x INHERITED_CLASS

%x CLASS_DEF
%x INHERITED_CLASS_DEF

%x CLASS_NAME_IN_CLASS
%x EXTERNAL_CLASS_ENTITY

%x CONSTRUCTOR
%x OPERATOR_FUNC
%x FLOWER

%x OBJECT
%x OBJECT_CLASS_NAME
%x OBJECT_ARGUMENTS
%x OBJECT_EQUATION


%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *classes[100];
int class_count=0, inherited_count=0, constructor_count=0, operator_func_count = 0, object_lines = 0, object_count = 0;
int temp_object_lines=0;
char *inherited_classes[100];
char *temp;
char *object_class;
char str[100];
// char data_types[10][2] = {"int", "float"};
int data_types_count = 2;
int flower_count = -1;
int parenthesis_count = -1;
int not_object = 0;

%}

ID      [a-zA-Z][a-zA-Z0-9_]*
SPACE   [ \t\n]
SECURITY "public"|"private"|"protected"
PARENTCLASS {SECURITY}{SPACE}*

%%

<INITIAL,CLASS,INHERITED_CLASS,CLASS_DEF,INHERITED_CLASS_DEF,CONSTRUCTOR,OPERATOR_FUNC,FLOWER,OBJECT,OBJECT_CLASS_NAME,OBJECT_ARGUMENTS,OBJECT_EQUATION>\/\/.*			    { }

<INITIAL,CLASS,INHERITED_CLASS,CLASS_DEF,INHERITED_CLASS_DEF,CONSTRUCTOR,OPERATOR_FUNC,FLOWER,OBJECT,OBJECT_CLASS_NAME,OBJECT_ARGUMENTS,OBJECT_EQUATION>"/*"				{ yy_push_state(C_COMMENT); }
<C_COMMENT>"*/" 										                                    { yy_pop_state(); }
<C_COMMENT>\n   										                                    { }
<C_COMMENT>.    										                                    { }

<INITIAL,CLASS,INHERITED_CLASS,CLASS_DEF,INHERITED_CLASS_DEF,CONSTRUCTOR,OPERATOR_FUNC,FLOWER,OBJECT,OBJECT_CLASS_NAME,OBJECT_ARGUMENTS,OBJECT_EQUATION>"\""				{ yy_push_state(STRING); }
<STRING>[^\n\"] 		{ }
<STRING>"\""											{ fprintf(yyout,"string"); yy_pop_state();}

"class"{SPACE}+                 						{ yy_push_state(CLASS); fprintf(yyout,"START CLASS"); ECHO;}
<CLASS>{ID}                     						{ temp=(char*)malloc((yyleng+1)*sizeof(char));strcpy(temp,yytext); ECHO; }
<CLASS>{SPACE}*\{              							{ yy_push_state(CLASS_DEF); ECHO;}
<CLASS_DEF>\}{SPACE}*";"       							{ yy_pop_state(); yy_pop_state(); ECHO; fprintf(yyout,"END CLASS"); classes[class_count++]=temp; }

<CLASS>{SPACE}*":"{SPACE}*								{ yy_push_state(INHERITED_CLASS); fprintf(yyout,"START INHERITED CLASS"); ECHO; }
<INHERITED_CLASS>{PARENTCLASS}?{ID}{SPACE}*\{			{ yy_push_state(INHERITED_CLASS_DEF); ECHO;}
<INHERITED_CLASS_DEF>\}{SPACE}*";"						{ yy_pop_state(); yy_pop_state(); yy_pop_state(); fprintf(yyout,"END INHERITED CLASS"); ECHO; inherited_classes[inherited_count++]=temp;classes[class_count++]=temp;}

<INITIAL,FLOWER>{ID}                                    { for (int i=0; i<class_count; i++){if (strcmp(yytext, classes[i])==0){object_class = classes[i]; fprintf(yyout,"START OBJECT"); yy_push_state(OBJECT_CLASS_NAME); break;}} ECHO;}
<CLASS_DEF,INHERITED_CLASS_DEF>{ID}						{ if (strcmp(yytext,temp)==0){fprintf(yyout,"CLASS_NAME_IN_CLASS");yy_push_state(CLASS_NAME_IN_CLASS);} else if (strcmp(yytext,"operator")==0){fprintf(yyout,"START OPERATOR_FUNC");yy_push_state(OPERATOR_FUNC);} else{for (int i=0; i<class_count; i++){if (strcmp(yytext, classes[i])==0){object_class = classes[i]; fprintf(yyout,"START OBJECT"); yy_push_state(OBJECT_CLASS_NAME); break;}}}  ECHO;}

<INITIAL>{ID}{SPACE}*\:\:                               { for (int i=0; i<=yyleng; i++){if (yytext[i]==' '||yytext[i]=='\t'||yytext[i]=='\n'||yytext[i]==':'){str[i]='\0';break;} else{str[i]=yytext[i];}} for (int i=0; i<class_count; i++){if (strcmp(str, classes[i])==0){temp = classes[i]; fprintf(yyout,"EXTERNAL_CLASS_ENTITY"); yy_push_state(EXTERNAL_CLASS_ENTITY); break;}} ECHO;}
<OBJECT_CLASS_NAME>{ID}{SPACE}*\:\:                                { for (int i=0; i<=yyleng; i++){if (yytext[i]==' '||yytext[i]=='\t'||yytext[i]=='\n'||yytext[i]==':'){str[i]='\0';break;} else{str[i]=yytext[i];}} for (int i=0; i<class_count; i++){if (strcmp(str, classes[i])==0){temp = classes[i]; yy_pop_state(); fprintf(yyout,"NOT OBJECT "); fprintf(yyout,"EXTERNAL_CLASS_ENTITY"); yy_push_state(EXTERNAL_CLASS_ENTITY); break; temp_object_lines=0;}} ECHO;}

<EXTERNAL_CLASS_ENTITY>{ID}                                   { if (strcmp(yytext,temp)==0){fprintf(yyout,"START CONSTRUCTOR"); yy_push_state(CONSTRUCTOR);} else if (strcmp(yytext,"operator")==0){ fprintf(yyout,"START OPERATOR_FUNC"); yy_pop_state(); yy_push_state(OPERATOR_FUNC);} else { yy_pop_state();} ECHO;}

<CLASS_NAME_IN_CLASS>{ID}								{ if(strcmp(yytext,"operator")==0){fprintf(yyout,"START OPERATOR_CL"); yy_pop_state(); yy_push_state(OPERATOR_FUNC);} else{yy_pop_state();} ECHO;}
<CLASS_NAME_IN_CLASS>\(									{ fprintf(yyout,"START CONSTRUCTOR"); yy_push_state(CONSTRUCTOR); ECHO;}

<CONSTRUCTOR>\{											{ fprintf(yyout,"START FLOWER"); yy_push_state(FLOWER);flower_count=1; ECHO;}
<CONSTRUCTOR>\;							    			{ yy_pop_state(); yy_pop_state(); ECHO; fprintf(yyout,"CONSTR_SEMI");}
<CONSTRUCTOR>[^\{]										{ ECHO; if (flower_count==0){yy_pop_state();yy_pop_state(); constructor_count++;flower_count=-1;}}

<OPERATOR_FUNC>\{										{ yy_push_state(FLOWER); flower_count=1; fprintf(yyout,"START FLOWER"); ECHO;}
<OPERATOR_FUNC>\;										{ yy_pop_state(); ECHO; fprintf(yyout,"OPER_SEMI");}
<OPERATOR_FUNC>[^\{]									{ ECHO; if (flower_count==0){yy_pop_state(); operator_func_count++;flower_count=-1;}}

<FLOWER>\{												{ flower_count++; ECHO;}
<FLOWER>\}												{ flower_count--;if (flower_count==0){yy_pop_state();} ECHO; fprintf(yyout,"END FLOWER");}

<OBJECT_CLASS_NAME>{ID}                                 { yy_pop_state(); yy_push_state(OBJECT); fprintf(yyout,"GOT OBJECT NAME"); ECHO; }

<OBJECT_CLASS_NAME>[^a-zA-Z \n\t]                       { yy_pop_state(); fprintf(yyout,"NOT OBJECT"); ECHO; }

<OBJECT_ARGUMENTS>\(											{ parenthesis_count++; ECHO;}
<OBJECT_ARGUMENTS>\)											{ parenthesis_count--; if (parenthesis_count==0){yy_pop_state();if (not_object==1) {yy_pop_state(); temp_object_lines=0;}} ECHO; fprintf(yyout,"END OBJECT_ARGUMENTS");}
<OBJECT_ARGUMENTS>{ID}                                  { if (not_object==0){for (int i=0; i<class_count; i++){if (strcmp(yytext, classes[i])==0){fprintf(yyout,"NOT OBJECT"); break; not_object=1;}}} ECHO;}

<OBJECT>\;                                              { yy_pop_state(); ECHO; temp_object_lines++; object_lines += temp_object_lines; object_count++; temp_object_lines=0; fprintf(yyout,"END OBJECT");}
<OBJECT>\=                                              { yy_pop_state(); fprintf(yyout,"START OBJECT_EQUATION"); ECHO; yy_push_state(OBJECT_EQUATION); }
<OBJECT>\(                                              { yy_push_state(OBJECT_ARGUMENTS); parenthesis_count=1; fprintf(yyout,"START OBJECT_ARGUMENTS"); ECHO;}

<OBJECT_EQUATION>\;                                     { yy_pop_state(); temp_object_lines++; object_lines += temp_object_lines; object_count++; temp_object_lines=0; ECHO; fprintf(yyout,"END OBJECT_EQUATION");}

<OBJECT,OBJECT_EQUATION,OBJECT_ARGUMENTS>\n { temp_object_lines++; ECHO; }

%%


int main()
{
    yyin=fopen("test.c","r");
    yyout=fopen("out.txt","w");
    yylex();
    printf("1) Objects declaration : %d\n", object_lines);
    printf("2) Class definition : %d\n", class_count);
    printf("3) Constructor definition : %d\n", constructor_count);
    printf("4) Inherited Class definition : %d\n", inherited_count);
    printf("5) Operator Overloaded function definition : %d\n", operator_func_count);
    // printf("%d\n", object_count);
    return 0;
}