#include <stdio.h>
int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int *p = a;
    int *q = &a[4];
    int n = 5;
    for (int i = 0; i < n / 2; i++)
    { 
        int temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}