#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    float **data;
} Matrix;

Matrix create_matrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (float **) malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = (float *) malloc(cols * sizeof(float));
    }
    return m;
}

void free_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
}

void print_matrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%f ", m.data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 3;
    int cols = 4;
    Matrix m = create_matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = i * cols + j;
        }
    }

    print_matrix(m);

    free_matrix(&m);

    return 0;
}
