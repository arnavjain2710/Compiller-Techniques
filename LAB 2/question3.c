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

// Function to handle multi-line comments
void handleMultiLineComment(FILE *file) {
    char line[MAX_LINE_LENGTH];
    int isMultiLineComment = 0;

    while (fgets(line, sizeof(line), file)) {
        char *start = strstr(line, "/*");
        char *end = strstr(line, "*/");

        if (isMultiLineComment) {
            // Continue printing multi-line comment lines
            printf("Multi-line comment: %s", line);
            if (end != NULL) {
                isMultiLineComment = 0;  // End of multi-line comment
            }
        } else if (start != NULL) {
            // Start of multi-line comment
            printf("Multi-line comment: %s", start);
            isMultiLineComment = 1;
            if (end != NULL) {
                isMultiLineComment = 0; // If the comment ends on the same line
            }
        }
    }
}

// Function to check if a line is a comment or not
int isCommentLine(char *line) {
    // Check if line contains single-line comment marker
    if (strstr(line, "//") != NULL) {
        return 1; // It's a comment
    }
    // Check if line contains multi-line comment markers
    if (strstr(line, "/*") != NULL || strstr(line, "*/") != NULL) {
        return 1; // It's a comment
    }
    return 0; // Not a comment
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
    int isInsideMultiLineComment = 0;

    while (fgets(line, sizeof(line), file)) {
        lineNumber++;

        // Check if inside a multi-line comment from previous lines
        if (isInsideMultiLineComment) {
            printf("Multi-line comment: %s", line);
            // Look for the ending marker of the multi-line comment
            if (strstr(line, "*/") != NULL) {
                isInsideMultiLineComment = 0;
            }
            continue;
        }

        // Check for a multi-line comment starting within the current line
        if (strstr(line, "/*") != NULL) {
            printf("Multi-line comment: %s", strstr(line, "/*"));
            isInsideMultiLineComment = 1;
            // Check if it ends within the same line
            if (strstr(line, "*/") != NULL) {
                isInsideMultiLineComment = 0;
            }
            continue;
        }

        // Check for single-line comments
        if (strstr(line, "//") != NULL) {
            printf("Single-line comment: %s\n", strstr(line, "//") + 2);
            continue;
        }

        // If the line is not a comment, output that it's not a comment
        printf("Line %d is not a comment: %s", lineNumber, line);
    }

    fclose(file);
    return 0;
}
