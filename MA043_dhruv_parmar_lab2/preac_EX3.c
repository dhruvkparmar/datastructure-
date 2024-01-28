// Create an array of 10 float numbers. Pass them to a function named average. Accept a
// number m from the user in the function. Calculate the average of the first m numbers of the
// array and return to the caller.
#include <stdio.h>

float average(float data[], int m) {
   float sum = 0.0;

    if (m <= 0 || m > 10) {
        printf("Invalid value for m. It must be between 1 and 10.\n");
        return -1; 
    }
    for (int i = 0; i < m; i++) {
        sum += data[i];
    }
    return sum / m;
}

int main() {
    float arr[10];
    int m, i;

    printf("Enter 10 float numbers: ");
    for (i = 0; i < 10; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Enter the value of m: ");
    scanf("%d", &m);

    float avg = average(arr, m);
    if (avg != -1) {  
        printf("Average of the first %d numbers: %.2f\n", m, avg);
    }
    return 0;
}
