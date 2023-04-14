#include <stdio.h>

typedef struct {
    void *data;
    size_t size;
} buffer;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    buffer buf;
    buf.data = arr;
    buf.size = sizeof(arr);
    int *ptr = (int *)buf.data;
    for (int i = 0; i < buf.size / sizeof(int); i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    return 0;
}
