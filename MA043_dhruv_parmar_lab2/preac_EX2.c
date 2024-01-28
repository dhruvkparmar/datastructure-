// Write a C program to copy one array to another using pointers. The size of both the arrays
// may be different.
#include <stdio.h>

int main() {
    int arr1[100], arr2[50], size1, size2, i;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    printf("Enter elements of the first array: ");
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array (less than or equal to %d): ", size1);
    scanf("%d", &size2);

    if (size2 > size1) {
        printf("Error: size2 cannot be greater than size1.\n");
        return 1;
    }

    int *ptr1 = arr1, *ptr2 = arr2;

    for (i = 0; i < size2; i++) {
        *ptr2++ = *ptr1++;
    }

    printf("Copied array: ");
    for (i = 0; i < size2; i++) {
        printf("%d ", arr2[i]);
    }

    printf("\n");

    return 0;
}
