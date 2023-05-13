#include <stdio.h>

#define SIZE 3

// Function to perform matrix multiplication
void multiplyMatrices(int matrix1[][SIZE], int matrix2[][SIZE], int result[][SIZE]) {
    int i, j, k;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result[i][j] = 0;

            for (k = 0; k < SIZE; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix1[SIZE][SIZE] = {
        {0b110, 0b011, 0b101},
        {0b001, 0b100, 0b010},
        {0b111, 0b000, 0b011}
    };

    int matrix2[SIZE][SIZE] = {
        {0b010, 0b001, 0b101},
        {0b100, 0b010, 0b011},
        {0b001, 0b110, 0b111}
    };

    int result[SIZE][SIZE];

    multiplyMatrices(matrix1, matrix2, result);

    printf("Matrix 1:\n");
    printMatrix(matrix1);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2);

    printf("\nMatrix Multiplication:\n");
    printMatrix(result);

    return 0;
}
