// #include <stdio.h>
// int passByRef(int *a, int *b)
// {
//     printf("\npass by reference");
//     *a = *a + *b;
//     *b = *a - *b;
//     *a = *a - *b;
//     printf("\na is :%d", *a);
//     printf("\nb is :%d", *b);
// }

// int passByValue(int a, int b)
// {
//     printf("pass by value");
//     a = a + b;
//     b = a - b;
//     a = a - b;
//     printf("\na is :%d", a);
//     printf("\nb is :%d", b);
// }
// int main()
// {
//     int a = 10, b = 20;

//     passByValue(a, b);
//     passByRef(&a, &b);
// }
#include <stdio.h>

// Function to swap two numbers using pass by value
void swapByValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapByValue function: a = %d, b = %d\n", a, b);
}

// Function to swap two numbers using pass by reference
void swapByReference(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Inside swapByReference function: a = %d, b = %d\n", *a, *b);
}

int main()
{
    int num1 = 10, num2 = 20;

 


    // Swap using pass by value
    printf("\nBefore swapByValue function: num1 = %d, num2 = %d\n", num1, num2);
    swapByValue(num1, num2);
    printf("After swapByValue function: num1 = %d, num2 = %d\n", num1, num2); // Values remain unchanged

    // Swap using pass by reference
    printf("\nBefore swapByReference function: num1 = %d, num2 = %d\n", num1, num2);
    swapByReference(&num1, &num2);
    printf("After swapByReference function: num1 = %d, num2 = %d\n", num1, num2); // Values are swapped

    return 0;
}
