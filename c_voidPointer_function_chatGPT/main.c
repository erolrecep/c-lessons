#include <stdio.h>
#include <stdlib.h>

void *create_array(int size, int initial_value) {
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = initial_value;
    }
    return (void *)arr;
}

int main() {
    int *arr = (int *)create_array(5, 0);
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
