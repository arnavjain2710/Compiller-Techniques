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
    input_file = fopen(argv[1], "r");
    yyin = input_file;
    yylex();
    printf("Number of printf statements: %d\n", printf_count);
    printf("Number of scanf statements: %d\n", scanf_count);
    fclose(input_file);
    return 0;
}


