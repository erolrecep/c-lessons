#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Person;

int compare_people(const void *a, const void *b) {
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    return strcmp(p1->name, p2->name);
}

int main() {
    Person people[] = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"},
        {4, "Dave"},
        {5, "Eve"}
    };
    int num_people = sizeof(people) / sizeof(people[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%d: %s\n", people[i].id, people[i].name);
    }

    qsort(people, num_people, sizeof(Person), compare_people);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%d: %s\n", people[i].id, people[i].name);
    }

    return 0;
}
