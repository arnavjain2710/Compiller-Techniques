%{
#include "q1.tab.h"         // Required for tokens
extern void yyerror(const char *s);  // Explicit declaration
%}

%%
A   { return A; }
B   { return B; }
\n  { return 0; }
.   { yyerror("Invalid character detected"); }
%%

int yywrap() { return 1; }
