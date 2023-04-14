#include <stdio.h>
#include <omp.h>

int main() {
    int n = 100;
    int a[n], b[n], c[n];

    // initialize arrays
    for (int i = 0; i < n; i++) {
        a[i] = i;
        b[i] = i;
    }

    // perform vector addition in parallel
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }

    // print result
    printf("c = [");
    for (int i = 0; i < n; i++) {
        printf("%d%s", c[i], i == n - 1 ? "]\n" : ", ");
    }

    return 0;
}
