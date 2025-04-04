%{
#include "q3.tab.h"
#include <string.h>
%}

%%
[a-zA-Z]+   { 
    strcpy(yylval.str, yytext); 
    return WORD; 
}
[ \t\n]     { return SPACE; }
.           { return OTHER; }
%%

int yywrap() {
    return 1;
}


