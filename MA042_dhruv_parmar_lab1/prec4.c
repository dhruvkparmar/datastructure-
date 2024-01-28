#include <stdio.h>
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 18, 89, 26, 87, 58, 78, 65, 74, 50, 68};
    int *ptr = arr;
    for (int i = 0; i < 15; i++)
    {
        printf("%d\t", *ptr++);
    }
}