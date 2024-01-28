#include <stdio.h>

void copyString(char *source, char *destination) {
    while (*source != '\0') {
        *destination = *source; 
        source++;
        destination++;
    }
    *destination = '\0'; // Adding null character at the end
}

void concatenateStrings(char *str1, char *str2, char *result) {
    while (*str1 != '\0') {
        *result = *str1;
        str1++;
        result++;
    }
    while (*str2 != '\0') {
        *result = *str2;
        str2++;
        result++;
    }
    *result = '\0'; // Adding null character at the end
}

int compareStrings(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0; // Not equal
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0'); // Equal if both are at the end
}

int main() {
    char string1[100], string2[100], result[200];

    // Copy one string to another
    printf("Enter the first string: ");
    scanf("%s", string1);

    copyString(string1, result);
    printf("Copied String: %s\n", result);

    // Concatenate two strings
    printf("Enter the second string: ");
    scanf("%s", string2);

    concatenateStrings(string1, string2, result);
    printf("Concatenated String: %s\n", result);

    // Compare two strings
    if (compareStrings(string1, string2)) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    return 0;
}