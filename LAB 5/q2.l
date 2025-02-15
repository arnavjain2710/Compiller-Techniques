%{
    int printf_count = 0;
    int scanf_count = 0;
    FILE *input_file;
%}

%%
"printf"  { printf_count++; }
"scanf"   { scanf_count++; }

%%
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening file");
        return 1;
    }
    yyin = input_file;
    yylex();
    printf("Number of printf statements: %d\n", printf_count);
    printf("Number of scanf statements: %d\n", scanf_count);
    fclose(input_file);
    return 0;
}

// commands:
// lex -o q2.c q2.l
// gcc q2.c -ll -o q2
// ./q2 dum.c

