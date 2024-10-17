#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define EMPTY -1   // Indicator for an empty slot
#define DELETED -2 // Indicator for a deleted slot

int hashTable[SIZE];

// Initialize the hash table with EMPTY markers
void init()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = EMPTY;
    }
}

// Primary hash function
int hash1(int value)
{
    return value % SIZE;
}

// Secondary hash function (ensures non-zero step size)
int hash2(int value)
{
    return 1 + (value % (SIZE - 1));
}

// Insert with double hashing
void insert(int value)
{
    int index = hash1(value);
    int stepSize = hash2(value);
    int i = 0;

    // Probe until an empty or deleted slot is found
    while (hashTable[(index + i * stepSize) % SIZE] != EMPTY && hashTable[(index + i * stepSize) % SIZE] != DELETED)
    {
        i++;
        if (i == SIZE)
        { // Full table looped through
            printf("Table is full, cannot insert %d\n", value);
            return;
        }
    }

    hashTable[(index + i * stepSize) % SIZE] = value;
    printf("Inserted %d at index %d\n", value, (index + i * stepSize) % SIZE);
}

// Delete with double hashing
void delete(int value)
{
    int index = hash1(value);
    int stepSize = hash2(value);
    int i = 0;

    // Probe until finding the value or an empty slot
    while (hashTable[(index + i * stepSize) % SIZE] != EMPTY)
    {
        if (hashTable[(index + i * stepSize) % SIZE] == value)
        {
            hashTable[(index + i * stepSize) % SIZE] = DELETED;
            printf("Deleted %d from index %d\n", value, (index + i * stepSize) % SIZE);
            return;
        }
        i++;
        if (i == SIZE)
        { // Full table looped through
            break;
        }
    }

    printf("Value %d not found in the table\n", value);
}

// Search with double hashing
int search(int value)
{
    int index = hash1(value);
    int stepSize = hash2(value);
    int i = 0;

    // Probe until finding the value or an empty slot
    while (hashTable[(index + i * stepSize) % SIZE] != EMPTY)
    {
        if (hashTable[(index + i * stepSize) % SIZE] == value)
        {
            printf("Found %d at index %d\n", value, (index + i * stepSize) % SIZE);
            return (index + i * stepSize) % SIZE;
        }
        i++;
        if (i == SIZE)
        { // Full table looped through
            break;
        }
    }

    printf("Value %d not found in the table\n", value);
    return -1;
}

// Print the hash table
void print()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == EMPTY)
        {
            printf("hashTable[%d] --> EMPTY\n", i);
        }
        else if (hashTable[i] == DELETED)
        {
            printf("hashTable[%d] --> DELETED\n", i);
        }
        else
        {
            printf("hashTable[%d] --> %d\n", i, hashTable[i]);
        }
    }
}

int main()
{
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
    delete (10);
    delete (3);
    delete (100); // Attempt to delete a non-existent element

    printf("\nHash table after deletions:\n");
    print();

    return 0;
}
