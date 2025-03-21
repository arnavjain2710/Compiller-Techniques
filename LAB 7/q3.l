%{
#include <stdio.h>
%}

%%
[\t ]+   ; /* ignore whitespace */
\n       { return 0; }

"am"|"is"|"are"|"was"|"were"|"being"|
"been"|"be"|"have"|"has"|"had"|"do"|
"does"|"did"|"will"|"would"|"shall"|
"should"|"may"|"might"|"must"|"can"|
"could"   { printf("%s: is a helping verb\n", yytext); }

[a-zA-Z]+       { printf("%s: is not a helping verb\n", yytext); }
.               { printf("%s: invalid token\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}





