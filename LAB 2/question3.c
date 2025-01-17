#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to check and print single-line comments
void checkSingleLineComment(char *line) {
    char *commentStart = strstr(line, "//");
    if (commentStart != NULL) {
        printf("Single-line comment: %s\n", commentStart + 2); // Skip "//"
    }
}

// Function to check and print multi-line comments
void checkMultiLineComment(FILE *file) {
    char line[MAX_LINE_LENGTH];
    int isMultiLineComment = 0;

    while (fgets(line, sizeof(line), file)) {
        char *start = strstr(line, "/*");
        char *end = strstr(line, "*/");

        if (isMultiLineComment) {
            // In multi-line comment
            printf("Multi-line comment: %s", line);
            if (end != NULL) {
                isMultiLineComment = 0;
            }
        } else if (start != NULL) {
            // Start of multi-line comment
            printf("Multi-line comment: %s", start);
            isMultiLineComment = 1;
            if (end != NULL) {
                // End of comment on the same line
                isMultiLineComment = 0;
            }
        }
    }
}

// Main function to read the file and check each line
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;

    while (fgets(line, sizeof(line), file)) {
        lineNumber++;

        // Check for single-line comment
        checkSingleLineComment(line);

        // Check for multi-line comment (we handle this after reading the entire file)
        checkMultiLineComment(file);
    }

    fclose(file);
    return 0;
}
