%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char target_word[100];
int count = 0;

void to_lowercase(char *str);
%}

%union {
    char str[100];
}

%token <str> WORD
%token SPACE OTHER
%type <str> S

%%

S : /* empty */
    | S WORD  {
        char temp[100];
        strcpy(temp, $2);
        to_lowercase(temp);

        if(strcmp(temp, target_word) == 0)
            count++;
    }
  | S SPACE { /* Ignore spaces */ }
  | S OTHER { /* Ignore other characters */ }
;

%%

void to_lowercase(char *str) {
    int i;
    for(i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int main() {
    printf("Enter the word to count: ");
    scanf("%s", target_word);
    
    // Convert target word to lowercase
    to_lowercase(target_word);
    
    printf("Enter the text (Ctrl+D to end on Unix, Ctrl+Z on Windows):\n");
    
    // Clear input buffer
    while(getchar() != '\n');
    
    yyparse();
    
    printf("The word \"%s\" appears %d times in the text.\n", target_word, count);
    return 0;
}

int yyerror(char *s) {
    printf("Error: %s\n", s);
    return 0;
}


