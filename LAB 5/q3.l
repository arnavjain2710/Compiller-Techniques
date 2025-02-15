%{
    int pos_int = 0;
    int neg_int = 0;
    int pos_frac = 0;
    int neg_frac = 0;
%}

%%
[+-]?[0-9]+  { 
    if (yytext[0] == '-') {
        neg_int++;  
    } else {
        pos_int++; 
    }
}

[+-]?[0-9]+\.[0-9]+  { 
    if (yytext[0] == '-') {
        neg_frac++;  
    } else {
        pos_frac++;  
    }
}

%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening file");
        return 1;
    }
    yyin = input_file;
    yylex();
    printf("Positive integers: %d\n", pos_int);
    printf("Negative integers: %d\n", neg_int);
    printf("Positive fractions: %d\n", pos_frac);
    printf("Negative fractions: %d\n", neg_frac);
    fclose(input_file);
    return 0;
}

// commands:
// lex -o q3.c q3.l
// gcc q3.c -ll -o q3
// ./q3 num.txt


