%{
#include <stdio.h>
%}

%union {
    int num;
}

%token <num> NUMBER
%token PLUS MINUS TIMES DIVIDE LPAREN RPAREN
%left PLUS MINUS
%left TIMES DIVIDE
%right UMINUS

%type <num> E T F

%%

S : E { printf("Result: %d\n", $1); }
;

E : E PLUS T    { $$ = $1 + $3; }
    | E MINUS T   { $$ = $1 - $3; }
    | T           { $$ = $1; }
;

T : T TIMES F   { $$ = $1 * $3; }
    | T DIVIDE F  { 
        if ($3 == 0) {
            yyerror("Division by zero");
            $$ = 0;
        } else {
            $$ = $1 / $3;
        }
    }
    | F           { $$ = $1; }
;

F : NUMBER      { $$ = $1; }
    | LPAREN E RPAREN { $$ = $2; }
    | MINUS F     { $$ = -$2; }
;

%%

int main() {
    printf("Enter an arithmetic expression: ");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Error: %s\n", s);
    return 0;
}