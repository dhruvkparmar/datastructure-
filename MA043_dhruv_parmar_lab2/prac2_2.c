#include <stdio.h>

int stringCompare(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {  
            return (*str1 - *str2);  
        }
        str1++;
        str2++;
    }

   
    return (*str1 - *str2);
}

int main() {
    char str1[50], str2[50];

    printf("Enter the first string: ");
    fgets(str1, 50, stdin);

    printf("Enter the second string: ");
    fgets(str2, 50, stdin);

    int result = stringCompare(str1, str2);

    if (result == 0) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    return 0;
}
