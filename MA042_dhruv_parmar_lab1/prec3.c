#include <stdio.h>
int main()
{
    int n = 10;
    int *p = &n;
    int **q = &p;
    printf("\naddress of n  : %d", &n);
    printf("\nvalue of n  : %d", n);

    printf("\naddress of  p pointer  : %d", &p); 
    printf("\nvalue of p  pointer : %d", p);

    printf("\naddress of q  double pointer : %d", &q);
    printf("\nvalue of q  double pointer : %d", q);
}