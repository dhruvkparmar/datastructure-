#include <stdio.h>

void removeChar(char *str, char ch) {
    char *writePtr = str;  
    while (*str != '\0') {
        if (*str != ch) {
            *writePtr++ = *str;  
        }
        str++; 

    *writePtr = '\0';
}
}

int main() {
    char str[100], ch;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    printf("Enter the character to remove: ");
    scanf(" %c", &ch);  
    removeChar(str, ch);

    printf("Corrected string: %s", str);

    return 0;
}
