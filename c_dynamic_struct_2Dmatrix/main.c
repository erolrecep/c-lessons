#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int **data;
    int rows;
    int cols;
} Matrix;

void init_matrix(Matrix *m) {
    m->data = (int **) malloc(m->rows * sizeof(int *));
    for (int i = 0; i < m->rows; i++) {
        m->data[i] = (int *) malloc(m->cols * sizeof(int));
        for (int j = 0; j < m->cols; j++) {
            /*The line m->data[i][j] = rand() % 10 initializes each element of the matrix
             with a random integer between 0 and 9.*/
            m->data[i][j] = rand() % 10;
        }
    }
}

void print_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    Matrix m;
    m.rows = 3;
    m.cols = 4;
    init_matrix(&m);
    print_matrix(&m);

    // Free memory
    for (int i = 0; i < m.rows; i++) {
        free(m.data[i]);
    }
    free(m.data);

    return 0;
}
