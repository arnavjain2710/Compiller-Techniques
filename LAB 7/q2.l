%{
#include "q2.tab.h"
%}

%option noyywrap


%%
"("     { return LPAREN; }
")"     { return RPAREN; }
"{"     { return LBRACE; }
"}"     { return RBRACE; }
<<EOF>> { return YYEOF; }
.|\n    ; 
%%



