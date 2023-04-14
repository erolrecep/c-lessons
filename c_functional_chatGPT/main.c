#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

int multiply(int x, int y) {
    return x * y;
}

int apply(int (*f)(int, int), int x, int y) {
    return f(x, y);
}

int main() {
    int x = 5, y = 10;
    int result;

    result = apply(add, x, y);
    printf("%d + %d = %d\n", x, y, result);

    result = apply(multiply, x, y);
    printf("%d * %d = %d\n", x, y, result);

    return 0;
}
