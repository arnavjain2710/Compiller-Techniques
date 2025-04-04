%{
#include <stdio.h>
#include <math.h>
void yyerror(char *);
int yylex(void);

int count = 0;  // Track fractional digit position
%}

%union {
    int digit;
    double val;
}

%token <digit> BINARY_DIGIT
%token DOT
%type <val> number integer_part fractional_part

%%
number:    integer_part DOT fractional_part {
                $$ = $1 + $3;
                printf("Decimal value: %.4f\n", $$);
           }
        ;

integer_part:    /* empty */       { $$ = 0.0; }
            | integer_part BINARY_DIGIT { $$ = $1 * 2 + $2; }
            ;

fractional_part: /* empty */       { $$ = 0.0; count = 0; }
            | fractional_part BINARY_DIGIT { 
                count++;
                $$ = $1 + $2 * pow(2, -count); 
            }
            ;
%%

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}
