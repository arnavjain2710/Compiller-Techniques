#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void checkSingleLineComment(char *line) {
    char *commentStart = strstr(line, "//");
    if (commentStart != NULL) {
        printf("Single-line comment: %s\n", commentStart + 2); 
    }
}

void handleMultiLineComment(FILE *file) {
    char line[MAX_LINE_LENGTH];
    int isMultiLineComment = 0;

    while (fgets(line, sizeof(line), file)) {
        char *start = strstr(line, "/*");
        char *end = strstr(line, "*/");

        if (isMultiLineComment) {

            printf("Multi-line comment: %s", line);
            if (end != NULL) {
                isMultiLineComment = 0;  
            }
        } else if (start != NULL) {
            printf("Multi-line comment: %s", start);
            isMultiLineComment = 1;
            if (end != NULL) {
                isMultiLineComment = 0; 
            }
        }
    }
}

int isCommentLine(char *line) {

    if (strstr(line, "//") != NULL) {
        return 1; 
    }
    if (strstr(line, "/*") != NULL || strstr(line, "*/") != NULL) {
        return 1; 
    }
    return 0; 
}

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

        if (isInsideMultiLineComment) {
            printf("Multi-line comment: %s", line);
            if (strstr(line, "*/") != NULL) {
                isInsideMultiLineComment = 0;
            }
            continue;
        }
        if (strstr(line, "/*") != NULL) {
            printf("Multi-line comment: %s", strstr(line, "/*"));
            isInsideMultiLineComment = 1;
            if (strstr(line, "*/") != NULL) {
                isInsideMultiLineComment = 0;
            }
            continue;
        }
        if (strstr(line, "//") != NULL) {
            printf("Single-line comment: %s\n", strstr(line, "//") + 2);
            continue;
        }
        printf("Line %d is not a comment: %s", lineNumber, line);
    }
    fclose(file);
    return 0;
}






