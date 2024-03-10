// Write a C program to scan two N x N matrices from the user. Perform addition
// of these matrices and store them in the third matrix. Use a single 3D
// dynamically generated array via pointer for the same.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    
    // Input the size of the matrices
    printf("Enter the size of the matrices (N): ");
    scanf("%d", &N);

    // Dynamically allocate memory for the matrices
    int ***matrices = (int ***)malloc(3 * sizeof(int **));
    if (matrices == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        matrices[i] = (int **)malloc(N * sizeof(int *));
        if (matrices[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        for (int j = 0; j < N; j++) {
            matrices[i][j] = (int *)malloc(N * sizeof(int));
            if (matrices[i][j] == NULL) {
                printf("Memory allocation failed\n");
                return 1;
            }
        }
    }

    // Input matrices from the user
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("enter element of 1 matirx [%d][%d] : ",i,j);
            scanf(" %d", &matrices[0][i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("enter element of 2 matirx [%d][%d] : ",i,j);
            scanf(" %d", &matrices[1][i][j]);
        }
    }

    // Perform addition and store the result in the third matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrices[2][i][j] = matrices[0][i][j] + matrices[1][i][j];
        }
    }

    // Display the result matrix
    printf("Resultant matrix after addition:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrices[2][i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            free(matrices[i][j]);
        }
        free(matrices[i]);
    }
    free(matrices);

    return 0;
}
