%{
#include "q1.tab.h"
void yyerror(char *);
%}

%%
[0-9]+          { yylval.num = atoi(yytext); return NUMBER; }
[+\-*/()]       { return yytext[0]; }
\n              { return '\n'; }  // Capture newline as token
[ \t]           ;  // Ignore only spaces/tabs
.               { yyerror("Invalid character"); }
%%

int yywrap() { return 1; }



