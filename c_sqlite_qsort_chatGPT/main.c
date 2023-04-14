#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>


/* TODO: To make it run this code, I need to create a sqlite db and write couple hundreds of
rows of data to people table */


#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Person;

int compare_people(const void *a, const void *b) {
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    return p1->id - p2->id;
}

int main() {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc;

    rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    rc = sqlite3_prepare_v2(db, "SELECT id, name FROM people", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    Person people[1000];
    int num_people = 0;

    while (sqlite3_step(stmt) == SQLITE_ROW && num_people < 1000) {
        people[num_people].id = sqlite3_column_int(stmt, 0);
        strncpy(people[num_people].name, (const char*)sqlite3_column_text(stmt, 1), MAX_NAME_LENGTH - 1);
        people[num_people].name[MAX_NAME_LENGTH - 1] = '\0';
        num_people++;
    }

    qsort(people, num_people, sizeof(Person), compare_people);

    rc = sqlite3_exec(db, "BEGIN", NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot begin transaction: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    for (int i = 0; i < num_people; i++) {
        char sql[100];
        sprintf(sql, "UPDATE people SET name='%s' WHERE id=%d", people[i].name, people[i].id);
        rc = sqlite3_exec(db, sql, NULL, NULL, NULL);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "Cannot execute statement: %s\n", sqlite3_errmsg(db));
            sqlite3_exec(db, "ROLLBACK", NULL, NULL, NULL);
            return 1;
        }
    }

    rc = sqlite3_exec(db, "COMMIT", NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot commit transaction: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}
