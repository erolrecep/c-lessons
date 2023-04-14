#include <stdio.h>
#include <stdlib.h>

int add(int x, int y) {
    return x + y;
}

int square(int x) {
    return x * x;
}

int is_even(int x) {
    return x % 2 == 0;
}

int reduce(int (*f)(int, int), int *xs, int n) {
    int result = xs[0];
    for (int i = 1; i < n; i++) {
        result = f(result, xs[i]);
    }
    return result;
}

void map(int (*f)(int), int *xs, int *ys, int n) {
    for (int i = 0; i < n; i++) {
        ys[i] = f(xs[i]);
    }
}

int filter(int (*f)(int), int *xs, int *ys, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (f(xs[i])) {
            ys[count++] = xs[i];
        }
    }
    return count;
}

int main() {
    int xs[] = {1, 2, 3, 4, 5};
    int n = sizeof(xs) / sizeof(int);

    // map example
    int ys[n];
    map(square, xs, ys, n);
    printf("map result: [");
    for (int i = 0; i < n; i++) {
        printf("%d%s", ys[i], i == n - 1 ? "]\n" : ", ");
    }

    // filter example
    int zs[n];
    int m = filter(is_even, xs, zs, n);
    printf("filter result: [");
    for (int i = 0; i < m; i++) {
        printf("%d%s", zs[i], i == m - 1 ? "]\n" : ", ");
    }

    // reduce example
    int sum = reduce(add, xs, n);
    printf("reduce result: %d\n", sum);

    return 0;
}
