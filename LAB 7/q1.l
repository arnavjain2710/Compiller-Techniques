%{
#include "q1.tab.h"
void yyerror(const char*);
%}

%option noyywrap

%%
[0-9]+          { yylval = atoi(yytext); return NUMBER; }
[+\-*/()\n]     { return yytext[0]; }
[ \t]           ; /* Ignore spaces/tabs */
.               { yyerror("Invalid character"); }
%%

