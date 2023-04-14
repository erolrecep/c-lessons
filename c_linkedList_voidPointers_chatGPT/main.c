#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
    void *data;
    struct node *next;
} node_t;

void push_front(node_t **head, void *data, size_t data_size) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = malloc(data_size);
    new_node->next = *head;
    *head = new_node;
    memcpy(new_node->data, data, data_size);
}

void print_list(node_t *head, void (*print_func)(void *)) {
    while (head != NULL) {
        print_func(head->data);
        head = head->next;
    }
}

void print_int(void *data) {
    printf("%d ", *(int *)data);
}

void print_float(void *data) {
    printf("%f ", *(float *)data);
}

int main() {
    node_t *head = NULL;
    int i1 = 1, i2 = 2, i3 = 3;
    float f1 = 1.1, f2 = 2.2, f3 = 3.3;

    push_front(&head, &i1, sizeof(int));
    push_front(&head, &i2, sizeof(int));
    push_front(&head, &i3, sizeof(int));

    printf("Int list: ");
    print_list(head, print_int);
    printf("\n");

    push_front(&head, &f1, sizeof(float));
    push_front(&head, &f2, sizeof(float));
    push_front(&head, &f3, sizeof(float));

    printf("Float list: ");
    print_list(head, print_float);
    printf("\n");

    return 0;
}
