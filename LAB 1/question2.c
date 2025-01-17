#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100  

int total_tokens = 0;

// Function to check if a string is a keyword
int isKeyword(char *word)
{
    char *keywords[] = {"int", "float", "char", "if", "else", "while", "for", "return", "void", NULL};
    for (int i = 0; keywords[i] != NULL; i++)
    {
        if (strcmp(word, keywords[i]) == 0)
        {
            total_tokens++;  
            return 1;
        }
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char c)
{
    char operators[] = "+-*/%=<>();,.{}#[]";
    for (int i = 0; operators[i] != '\0'; i++)
    {
        if (c == operators[i])
        {
            total_tokens++;  
            return 1;
        }
    }
    return 0;
}

// Function to check if a string is an identifier (variable/function name)
int isIdentifier(char *word)
{
    if (!isalpha(word[0]) && word[0] != '_')
    {
        return 0;
    }
    for (int i = 1; i < strlen(word); i++)
    {
        if (!isalnum(word[i]) && word[i] != '_')
        {
            return 0;
        }
    }
    total_tokens++;  
    return 1;
}

// Function to check if a string is a number (integer or float)
int isNumber(char *word)
{
    int i = 0;
    int hasDecimal = 0;

    // Check for negative sign at the start
    if (word[0] == '-')
        i = 1;

    for (; i < strlen(word); i++)
    {
        if (word[i] == '.')
        {
            if (hasDecimal)  // More than one decimal point is not valid
                return 0;
            hasDecimal = 1;
        }
        else if (!isdigit(word[i]))
        {
            return 0;
        }
    }

    total_tokens++;  
    return 1;
}

// Function to check if a string is a string literal
int isStringLiteral(char *word)
{
    return word[0] == '"' && word[strlen(word) - 1] == '"';
}

// Function to skip comments (single-line and multi-line)
void skipComments(FILE *file)
{
    char c, next;

    while ((c = fgetc(file)) != EOF)
    {
        if (c == '/' && (next = fgetc(file)) == '/')  // Single-line comment
        {
            while ((c = fgetc(file)) != EOF && c != '\n');  // Skip until end of line
        }
        else if (c == '/' && next == '*')  // Multi-line comment
        {
            while ((c = fgetc(file)) != EOF)
            {
                if (c == '*' && (next = fgetc(file)) == '/')  // End of multi-line comment
                {
                    break;
                }
            }
        }
        else 
        {
            ungetc(c, file);  // Push the character back for processing
            break;  // Exit the loop once we've reached a non-comment character
        }
    }
}

// Function to analyze and print tokens
void analyzeTokens(FILE *file)
{
    char word[MAX_LENGTH];
    char c;
    int i = 0;

    while ((c = fgetc(file)) != EOF)
    {
        skipComments(file);  // Skip comments
        char d;
        if (isalpha(c) || c == '_')  // Start of a possible identifier or keyword
        {
            word[i++] = c;
        }
        else if (c == '"')  // Start of a string literal
        {
            word[i++] = c;
            while ((c = fgetc(file)) != EOF && c != '"')  // Read string literal until closing quote
            {
                word[i++] = c;
            }
            word[i++] = '"';
            word[i] = '\0';  // Null-terminate string literal
            printf("String Literal: %s\n", word);
            total_tokens++;  // Increment token count for string literals
            i = 0;
        }
        else if (isdigit(c) || (c == '-' && ( isdigit(d = fgetc(file)))))  // Start of a number
        {
            word[i++] = c;
            ungetc(d, file);  // Push the character back for number processing
            while ((c = fgetc(file)) != EOF && (isdigit(c) || c == '.'))
            {
                word[i++] = c;
            }
            word[i] = '\0';  // Null-terminate the number
            if (isNumber(word))  // Check if it's a valid number
            {
                printf("Number    : %s\n", word);  // Print the number token
            }
            i = 0;  // Reset for the next token
        }
        else
        {
            if (i > 0)  // End of an identifier or keyword
            {
                word[i] = '\0';
                if (isKeyword(word))  // Check for keyword
                {
                    printf("Keyword   : %s\n", word);
                }
                else if (isIdentifier(word))  // Check for identifier
                {
                    printf("Identifier: %s\n", word);
                }
                i = 0;  // Reset for the next word
            }

            if (isOperator(c))  // Check for operator
            {
                printf("Operator  : %c\n", c);
            }
        }
    }

    printf("Total token count: %d\n", total_tokens);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file %s.\n", argv[1]);
        return 1;
    }

    analyzeTokens(file);
    fclose(file);
    return 0;
}