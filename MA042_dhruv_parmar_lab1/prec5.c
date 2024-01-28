#include <stdio.h>
int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int *p[5];
    for (int i = 0; i < 5; i++)
    {
        p[i] = &a[i];
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\n address %d  of value : %d", p[i], *p[i]);
    }
}