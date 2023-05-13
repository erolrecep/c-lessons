#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define SIZE 128

// Function to perform matrix multiplication
void multiplyMatrices(int matrix1[][SIZE], int matrix2[][SIZE], int result[][SIZE]) {
    int i, j, k;

    #pragma omp parallel for private(i, j, k) shared(matrix1, matrix2, result)
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

// Function to generate random values for a matrix
void generateRandomMatrix(int matrix[][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 2; // Assigning either 0 or 1 randomly
        }
    }
}

int main() {
    srand(time(0)); // Seed the random number generator

    int matrix1[SIZE][SIZE];
    int matrix2[SIZE][SIZE];
    int result[SIZE][SIZE];

    generateRandomMatrix(matrix1);
    generateRandomMatrix(matrix2);

    multiplyMatrices(matrix1, matrix2, result);

    printf("Matrix 1:\n");
    printMatrix(matrix1);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2);

    printf("\nMatrix Multiplication:\n");
    printMatrix(result);

    return 0;
}
