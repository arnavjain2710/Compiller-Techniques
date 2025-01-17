#include <stdio.h>
#include <string.h>

int isKeyword(char *str)
{
    char *keywords[] = {
        "int", "float", "char", "if", "else", "while", "for", "return", "void", "switch",
        "case", "break", "continue", "default", "struct", "union", "typedef", "long",
        "short", "unsigned", "signed", "enum", "const", "volatile", "goto", "NULL" , NULL};

    for (int i = 0; keywords[i] != NULL; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
        {
            return 1; 
        }
    }
    return 0; 
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    if (isKeyword(str))
    {
        printf("\"%s\" is a keyword.\n", str);
    }
    else
    {
        printf("\"%s\" is not a keyword.\n", str);
    }

    return 0;
}





