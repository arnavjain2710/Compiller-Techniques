%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char*);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%start start

%%
start:  expr '\n'        { printf("Result: %d\n", $1); exit(0); }
      | error '\n'       { exit(1); }
      ;

expr:   expr '+' expr    { $$ = $1 + $3; }
      | expr '-' expr    { $$ = $1 - $3; }
      | expr '*' expr    { $$ = $1 * $3; }
      | expr '/' expr    { $$ = $1 / $3; }
      | '(' expr ')'     { $$ = $2; }
      | NUMBER           { $$ = $1; }
      ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter expression (e.g., 2+2*3): ");
    yyparse();
    return 0;
}


