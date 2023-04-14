#include <stdio.h>

void my_callback(int arg) {
    printf("Callback called with argument: %d\n", arg);
}

void call_with_callback(void (*callback)(int), void *callback_arg) {
    int arg = 42;
    callback(arg);
    printf("Callback argument was: %p\n", callback_arg);
}

int main() {
    void *callback_arg = (void *)"Hello, world!";
    call_with_callback(my_callback, callback_arg);
    return 0;
}
