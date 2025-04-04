%{
#include "q4.tab.h"
%}

%%
"a"         { return A; }
"b"         { return B; }
[ \t\n]     { /* Ignore whitespace */ }
.           { return yytext[0]; }
%%

int yywrap() {
    return 1;
}

