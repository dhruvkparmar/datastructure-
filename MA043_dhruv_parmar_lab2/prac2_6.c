#include <stdio.h>

int main() {
   
    int sales[4][4] = {
        {100, 200, 300, 400},  
        {500, 600, 700, 800},  
        {900, 1000, 1100, 1200},  
        {1300, 1400, 1500, 1600}  
    };

    int (*ptr)[4] = sales;

    char quarter, company;

    printf("Enter quarter (Q1, Q2, Q3, Q4): ");
    scanf(" %c", &quarter);
    printf("Enter company (C1, C2, C3, C4): ");
    scanf(" %c", &company);

    int quarterIndex = quarter - 'Q' - 1;  
    int companyIndex = company - 'C';  

    int salesFigure = *(ptr + quarterIndex)[companyIndex];  
    printf("Sales figure for %c%c: %d\n", quarter, company, salesFigure);

    return 0;
}
