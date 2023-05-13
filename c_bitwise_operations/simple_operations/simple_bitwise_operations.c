#include <stdio.h>
#include <stdlib.h>


void bitwiseAND(int a, int b) {
    int result = a & b;
    printf("%d & %d = %d\n", a, b, result);
}

void bitwiseOR(int a, int b) {
    int result = a | b;
    printf("%d | %d = %d\n", a, b, result);
}

void bitwiseXOR(int a, int b) {
    int result = a ^ b;
    printf("%d ^ %d = %d\n", a, b, result);
}

void bitwiseNOT(int a) {
    int result = ~a;
    printf("~%d = %d\n", a, result);
}

void leftShift(int a, int shift) {
    int result = a << shift;
    printf("%d << %d = %d\n", a, shift, result);
}

void rightShift(int a, int shift) {
    int result = a >> shift;
    printf("%d >> %d = %d\n", a, shift, result);
}

int main() {
    int a = 5;
    int b = 3;
    int shift = 2;
    
    bitwiseAND(a, b);
    bitwiseOR(a, b);
    bitwiseXOR(a, b);
    bitwiseNOT(a);
    leftShift(a, shift);
    rightShift(a, shift);
    
    return 0;
}
