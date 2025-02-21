%{
#include "q2.tab.h"
extern int operands, operators;
extern int has_error;
extern void yyerror(const char *s);
%}

%%
[a-zA-Z_][a-zA-Z0-9_]* { operands++; return ID; }
[0-9]+(\.[0-9]*)?      { operands++; return NUMBER; }
"+"                     { operators++; return ADD; }
"-"                     { operators++; return SUB; }
"*"                     { operators++; return MUL; }
"/"                     { operators++; return DIV; }
\n                      { return END; }
[() \t]                ;
.                       { yyerror("Invalid token"); }
%%

int yywrap() { return 1; }
