#include <stdio.h>
#include <string.h>
#include <ctype.h>


void normalizeString(char* str, char* normalized) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            normalized[j++] = tolower(str[i]);
        }
    }
    normalized[j] = '\0';
}

int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0; 
        }
    }
    return 1; 
}


int isRotatedPalindrome(char* str) {
    char normalized[1000];
    normalizeString(str, normalized);

    int len = strlen(normalized);

    for (int i = 0; i < len; i++) {
        char rotated[1000];

        for (int j = 0; j < len; j++) {
            rotated[j] = normalized[(i + j) % len];
        }
        rotated[len] = '\0';

        if (isPalindrome(rotated)) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    
    char str[1000];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    if (isRotatedPalindrome(str)) {
        printf("The string is a rotated palindrome.\n");
    } else {
        printf("The string is not a rotated palindrome.\n");
    }

    return 0;
}
