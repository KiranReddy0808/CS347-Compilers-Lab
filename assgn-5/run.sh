bison --defines -v parser.y
flex lexer.l
g++-8 -std=c++11 lex.yy.c parser.tab.c compiler.cpp -o compiler
