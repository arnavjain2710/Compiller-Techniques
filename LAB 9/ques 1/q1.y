%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char *str);
%}

%union {
    char str[100];
}

%token <str> STRING
%type <str> E

%%

S : E {
    if(is_palindrome($1))
        printf("\"%s\" is a palindrome.\n", $1);
    else
        printf("\"%s\" is not a palindrome.\n", $1);
}
;

E : STRING { strcpy($$, $1); }
;

%%

int is_palindrome(char *str) {
    int i, j;
    int len = strlen(str);
    
    // Convert to lowercase for case-insensitive comparison
    for(i = 0; i < len; i++)
        str[i] = tolower(str[i]);
    
    for(i = 0, j = len - 1; i < j; i++, j--) {
        if(str[i] != str[j])
            return 0;
    }
    return 1;
}

int main() {
    printf("Enter a string to check if it's a palindrome: ");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Error: %s\n", s);
    return 0;
}