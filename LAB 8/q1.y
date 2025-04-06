%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(char *);
%}

%union { int num; }
%token <num> NUMBER
%type <num> expr
%left '+' '-'
%left '*' '/'
%right UMINUS

%%
input:    /* empty */
        | input expr '\n'  { printf("\n"); }
        ;

expr:    NUMBER          { printf("%d ", $1); }
        | '(' expr ')'   { $$ = $2; }
        | expr '+' expr  { printf("+ "); }
        | expr '-' expr  { printf("- "); }
        | expr '*' expr  { printf("* "); }
        | expr '/' expr  { printf("/ "); }
        | '-' expr %prec UMINUS { printf("- "); $$ = $2; }
        ;
%%

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter expression: ");
    fflush(stdout);  // Force prompt display
    yyparse();
    return 0;
}


