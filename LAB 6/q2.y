%{
#include <stdio.h>
int operands = 0, operators = 0;
int has_error = 0;
int yylex(void);
void yyerror(const char *s);
%}

%token ID NUMBER END
%token ADD SUB MUL DIV  // Individual operator tokens
%left ADD SUB
%left MUL DIV
%left UMINUS

%%
start: expr END { 
    if (!has_error) {
        printf("Valid Expression\nOperands: %d\nOperators: %d\n", operands, operators);
    }
};

expr: expr ADD expr
     | expr SUB expr
     | expr MUL expr
     | expr DIV expr
     | SUB expr %prec UMINUS
     | '(' expr ')'
     | ID
     | NUMBER
     ;
%%

void yyerror(const char *s) {
    has_error = 1;
    printf("Error: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}
