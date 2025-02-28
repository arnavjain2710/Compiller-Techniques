%{
    int count = 0;
    char output[1000]; 
    int index_string = 0;
%}

%%
[a-zA-Z]  {
                char c = yytext[0];  
                int shift = 2 + count;  
                if (shift > 25) {
                    shift = 1;  
                }

                if (c >= 'a' && c <= 'z') {
                    c = ((c - 'a' + shift) % 26) + 'a';
                } else if (c >= 'A' && c <= 'Z') {
                    c = ((c - 'A' + shift) % 26) + 'A';
                }

                output[index_string++] = c;  
                count++;  
            }
.|\n    { output[index_string++] = yytext[0]; }  

%%

int main() {
    printf("Enter the word: ");
    fflush(stdout); 
    yylex(); 
    output[index_string] = '\0'; 
    printf("\nThe new word is: %s\n", output);  
    return 0;
}

// commands to run:
// lex -o q1.c q1.l
// gcc q1.c -ll -o q1
// ./q1
// press Crtl + D to enter the word

