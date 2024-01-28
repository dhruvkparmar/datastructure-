#include <stdio.h>
#include <string.h>

int isPalindrome(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1; 

    while (start < end) {
        if (*start != *end) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
