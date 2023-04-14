#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the matrix with some values
    int count = 1;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = count++;
        }
    }

    // Print the matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the dynamically allocated memory
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
