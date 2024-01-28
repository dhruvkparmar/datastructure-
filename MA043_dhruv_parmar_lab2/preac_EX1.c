// Write a C program to copy a string to another without using strcpy function. Use pointers
// for both the strings.
#include <stdio.h>

int main() {
   char str1[100], str2[100];
   char *ptr1 = str1, *ptr2 = str2;

   printf("Enter a string: ");
   fgets(str1, 100, stdin);

   while (*ptr1 != '\0') {
       *ptr2++ = *ptr1++;
   }

   *ptr2 = '\0';

   printf("Copied string: %s", str2);

   return 0;
}
