%{
#include <stdio.h>
int yylex(void);                 // Explicit declaration
void yyerror(const char *s);     // Const-correct prototype
%}

%token A B

%%
start: a_seq b_seq ;

a_seq: /* empty */ | a_seq A ;
b_seq: /* empty */ | b_seq B ;
%%

void yyerror(const char *s) {
    printf("ERROR: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}
