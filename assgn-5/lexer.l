%option noyywrap

%{
#include <bits/stdc++.h>
#include "parser.tab.h"
#include "compiler.h"
using namespace std;

%}

%option yylineno
%option noyywrap


ID      [a-zA-Z][a-zA-Z0-9_]*
SPACE   [ \n\t]+
INT_NUMBER [0-9]+
FLOAT_NUMBER   INT_NUMBER\.INT_NUMBER
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
"int"                   return INT;
"float"                 return FLOAT;
"void"                  return VOID;
"main"                  return MAIN;
{INT_NUMBER}            return INT_NUMBER;
{FLOAT_NUMBER}          return FLOAT_NUMBER;
{ID}                    return ID;
{SPACE}                 ;
<<EOF>>                 return END;
.                       return ERROR;


%%
