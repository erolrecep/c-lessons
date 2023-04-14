#include <stdio.h>

typedef struct {
    void *data;
    void (*print)(void *);
} Object;

void print_int(void *data) {
    int *i = (int *)data;
    printf("The integer is: %d\n", *i);
}

void print_string(void *data) {
    char *s = (char *)data;
    printf("The string is: %s\n", s);
}

int main() {
    Object obj1, obj2;
    int i = 10;
    char *s = "Hello, world!";

    // Initialize obj1 with an integer value and a print function for integers
    obj1.data = &i;
    obj1.print = print_int;

    // Initialize obj2 with a string value and a print function for strings
    obj2.data = s;
    obj2.print = print_string;

    // Call the print function for obj1
    obj1.print(obj1.data);

    // Call the print function for obj2
    obj2.print(obj2.data);

    return 0;
}
