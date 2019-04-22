%option noyywrap

%{
#include <bits/stdc++.h>
#include "compiler.h"
#include "parser.tab.h"
using namespace std;

%}


ID      [a-zA-Z][a-zA-Z0-9_]*
SPACE   [ \n\t]+
DIGIT [0-9]
INTEGER {DIGIT}+
EXPONENT [eE][+-]?{INTEGER}
REAL {INTEGER}("."{INTEGER})?{EXPONENT}?
STRING  \'[^\'\n]*\'|\"[^\"\n]*\"

%%

">="                    return GTE;
"<="                    return LTE;
"<"                     return LT;
">"                     return GT;
"!="                    return NEQ;
"=="                    return EQ;
"="                     return ASGN;
"&&"                    return AND;
"||"                    return OR;
"!"                     return NOT;
"+"                     return PLUS;
"-"                     return MINUS;
"*"                     return TIMES;
"/"                     return DIVIDE;
"%"                     return MODULO;
"++"                    return INCREMENT;
"--"                    return DECREMENT;
"("                     return OPEN_PAR;
")"                     return CLOSE_PAR;
"{"                     return OPEN_CURLY;
"}"                     return CLOSE_CURLY;
"["                     return OPEN_BRAC;
"]"                     return CLOSE_BRAC;
","                     return COMMA;
";"                     return SEMI;
":"                     return COLON;
"for"                   return FOR;
"while"                 return WHILE;
"if"                    return IF;
"else"                  return ELSE;
"switch"                return SWITCH;
"case"                  return CASE;
"default"               return DEFAULT;
"break"                 return BREAK;
"continue"              return CONTINUE;
"const"                 return CONST;
"static"                return STATIC;
"extern"                return EXTERN;
"int"                   return INT;
"float"                 return FLOAT;
"void"                  return VOID;
"return"                return RETURN;
{REAL}                  { yylval.node = new Node("num", yytext); return REAL;}
{ID}                    { yylval.node = new Node("id", yytext); return ID;}
{SPACE}                 ;
<<EOF>>                 return END;
.                       return ERROR;


%%
