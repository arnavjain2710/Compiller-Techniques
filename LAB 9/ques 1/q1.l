%{
#include <stdio.h>
#include "q1.tab.h"
#include <string.h>
%}

%%
[a-zA-Z0-9]+ { 
    strcpy(yylval.str, yytext);
    return STRING; 
}
\n          { return 0; }
.           { /* Ignore all other characters */ }
%%

int yywrap() {
    return 1;
}



