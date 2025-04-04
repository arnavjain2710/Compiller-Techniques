%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+      { yylval.num = atoi(yytext); return NUMBER; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return TIMES; }
"/"         { return DIVIDE; }
"("         { return LPAREN; }
")"         { return RPAREN; }
[ \t]       { /* Ignore whitespace */ }
\n          { return 0; }
.           { printf("Unexpected character: %s\n", yytext); }
%%

int yywrap() {
    return 1;
}