#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int key;
    int value;
} Entry;


#define TABLE_SIZE 100

Entry hashTable[TABLE_SIZE];


/* Bitwise XOR Hashing */
int hashFunction(int key) {
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = (key >> 16) ^ key;
    return key % TABLE_SIZE;
}


void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = -1; // An invalid key to indicate an empty entry
        hashTable[i].value = -1; // An invalid value or any default value
    }
}

void insertHash(int key, int value) {
    int index = hashFunction(key);
    while (hashTable[index].key != -1) {
        index = (index + 1) % TABLE_SIZE; // Linear probing to find an empty slot
    }
    hashTable[index].key = key;
    hashTable[index].value = value;
}


int getHash(int key) {
    int index = hashFunction(key);
    while (hashTable[index].key != key) {
        if (hashTable[index].key == -1) {
            return -1; // Key not found
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing to find the key
    }
    return hashTable[index].value;
}


void removeHash(int key) {
    int index = hashFunction(key);
    while (hashTable[index].key != key) {
        if (hashTable[index].key == -1) {
            return; // Key not found
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing to find the key
    }
    hashTable[index].key = -1;
    hashTable[index].value = -1;
}


void printHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].key != -1) {
            printf("Index %d: Key = %d, Value = %d\n", i, hashTable[i].key, hashTable[i].value);
        }
    }
}



int main(int argc, char const *argv[])
{
    
    initializeHashTable();
    printHashTable();

    insertHash(10, 63);
    insertHash(5, 78);
    insertHash(7, 23);
    insertHash(12, 88);
    insertHash(1, 11);

    printHashTable();


    return 0;
}


