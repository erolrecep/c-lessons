#include <stdio.h>

// define a function pointer
typedef int (*lambda_function)(int);

// define a function template that takes a function pointer as an argument
void call_with_5(lambda_function f) {
    int result = f(5);
    printf("Result: %d\n", result);
}

int main() {
    // define a lambda function using a function pointer
    lambda_function lambda = [](int x) -> int { return x * x; }; // This line of code is not valid in C

    // call the lambda function using the function template
    call_with_5(lambda);

    return 0;
}


/*
    References
    1. https://hackaday.com/2019/09/11/lambdas-for-c-sort-of/
    2. https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2892.pdf
*/