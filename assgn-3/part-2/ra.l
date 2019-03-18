%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include "ra.tab.h"
%}

ID      [a-zA-Z][a-zA-Z0-9_]*
SPACE   [ \t]+
DIGIT [0-9]
INTEGER {DIGIT}+
EXPONENT [eE][+-]?{INTEGER}
REAL {INTEGER}("."{INTEGER})?{EXPONENT}?
STRING  \'[^\'\n]*\'|\"[^\"\n]*\"

%%

"SELECT"                return SELECT;
"PROJECT"               return PROJECT;
"CARTESIAN_PRODUCT"     return PRODUCT;
"EQUI_JOIN"             return JOIN;
">="                    return GTE;
"<="                    return LTE;
"<"                     return LT;
">"                     return GT;
"!="                    return NEQ;
"="                     return EQ;
"AND"                   return AND;
"OR"                    return OR;
"+"                     return PLUS;
"-"                     return MINUS;
"*"                     return TIMES;
"/"                     return DIVIDE;
"("                     return OPEN_PAR;
")"                     return CLOSE_PAR;
","                     return COMMA;
{REAL}                  return NUMBER;
{STRING}                return STRING;
{ID}                    return ID; 
"."                     return DOT;
"\n"                    return NEWLINE;
{SPACE}                 ;
<<EOF>>                 return END;
.                       return ERROR;



%%
