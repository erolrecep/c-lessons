#include <stdio.h>
#include <string.h>

void swap(void* a, void* b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int main() {
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b, sizeof(int));
    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
}
