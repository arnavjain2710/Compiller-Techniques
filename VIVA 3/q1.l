%{
#include <stdio.h>
%}

%%
[\t ]+   ; 
\n       { return 0; }

"am"|"is"|"are"|"was"|"were"|"being"|"been"|"be"|"have":  { printf("%s:helping verb\n", yytext); }

[a-zA-Z]+       { printf("%s:not helping verb\n", yytext); }
.               { printf("%s:invalid token\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}





