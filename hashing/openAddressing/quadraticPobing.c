#include <stdio.h>
#include <stdlib.h>
#define SIZE 7
#define EMPTY -1 // Indicator for empty slot
#define DELETED -2 // Indicator for deleted slot

int hashTable[SIZE];

// Initialize hash table
void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Quadratic probing insert
void insert(int value) {
    int key = value % SIZE;
    int index = key;
    int i = 1;

    // Quadratic probing to find an empty slot
    while (hashTable[index] != EMPTY && hashTable[index] != DELETED) {
        index = (key + i * i) % SIZE;
        i++;
        if (i == SIZE) { // Avoid infinite loop in full table
            printf("Table is full, cannot insert %d\n", value);
            return;
        }
    }

    hashTable[index] = value;
    printf("Inserted %d at index %d\n", value, index);
}

// Quadratic probing delete
void delete(int value) {
    int key = value % SIZE;
    int index = key;
    int i = 1;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == value) {
            hashTable[index] = DELETED; // Mark the slot as deleted
            printf("Deleted %d from index %d\n", value, index);
            return;
        }
        index = (key + i * i) % SIZE;
        i++;
        if (i == SIZE) { // Full loop completed, value not found
            break;
        }
    }

    printf("Value %d not found in the table\n", value);
}

// Quadratic probing search
int search(int value) {
    int key = value % SIZE;
    int index = key;
    int i = 1;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == value) {
            printf("Found %d at index %d\n", value, index);
            return index;
        }
        index = (key + i * i) % SIZE;
        i++;
        if (i == SIZE) { // Full loop completed, value not found
            break;
        }
    }

    printf("Value %d not found in the table\n", value);
    return -1;
}

// Print hash table
void print() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY) {
            printf("hashTable[%d] --> EMPTY\n", i);
        } else if (hashTable[i] == DELETED) {
            printf("hashTable[%d] --> DELETED\n", i);
        } else {
            printf("hashTable[%d] --> %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    init();
    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);

    printf("\nHash table after insertions:\n");
    print();

    // Search for elements
    search(10);
    search(3);
    search(100); // Should not be found

    // Test delete operation
    delete(10);
    delete(3);
    delete(100); // Attempt to delete non-existent element

    printf("\nHash table after deletions:\n");
    print();

    return 0;
}
