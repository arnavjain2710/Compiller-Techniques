%{
#include <stdio.h>
#include <stdlib.h>
%}

/* Tokens for the grammar */
%token A B

%%
/* Grammar: A -> aAb | bBa | ε */

start : expr  { printf("Input string follows the grammar rule.\n"); }
    ;

expr : /* epsilon */
    A expr B       /* This represents aAb */
    | B expr_b A     /* This represents bBa */
    |
    ;

expr_b : /* epsilon */
    |    /* This represents aAb */
    ;

%%

int main() {
    printf("Enter a string to check if it follows the grammar:\n");
    printf("A -> aAb | bBa | ε\n");
    printf("B -> ε\n");
    
    if(yyparse() == 0)
        printf("Parsing completed successfully.\n");
    else
        printf("The input does not follow the grammar.\n");
    
    return 0;
}

int yyerror(char *s) {
    printf("Error: %s - Input does not follow the grammar.\n", s);
    return 0;
}


