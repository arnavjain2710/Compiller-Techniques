%{
#include "q2.tab.h"
void yyerror(char *);  // Explicit error declaration
extern int count;       // Access YACC's counter
%}

%%
0               { yylval.digit = 0; return BINARY_DIGIT; }
1               { yylval.digit = 1; return BINARY_DIGIT; }
\.              { return DOT; }
[ \t\n]         ;  // Ignore whitespace
.               { yyerror("Invalid binary character"); }
%%

int yywrap() { return 1; }
