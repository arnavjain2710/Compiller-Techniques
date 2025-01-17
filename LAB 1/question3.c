#include <stdio.h>

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
    char c;
    int spaces = 0, lines = 0, characters = 0;
    while ((c = fgetc(file)) != EOF)
    {
        characters++;

        if (c == ' ')
        {
            spaces++;
        }

        if (c == '\n')
        {
            lines++;
        }
    }
    fclose(file);
    printf("Total characters: %d\n", characters);
    printf("Total spaces: %d\n", spaces);
    printf("Total lines ( if a line is defined as identifying new line special character): %d\n", lines);
    printf("Total lines ( if a line is defined as per english language): %d\n", lines+1);
    return 0;
}
