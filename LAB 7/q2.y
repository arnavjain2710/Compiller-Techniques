%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char*);
%}

%token LPAREN RPAREN LBRACE RBRACE YYEOF

%%
program:

    | program Parentheses { printf("Parentheses balanced\n"); exit(0); }
    ;

Parentheses:
    LPAREN program RPAREN
    | LBRACE program RBRACE
    ;


%%

void yyerror(const char *s) {
    printf("Parentheses not balanced\n");
    exit(1);
}

int main() {
    yyparse();
    return 0;
}




