#include <stdio.h>
#include <stdlib.h>

#define SIZE 10     // Define size of the hash table
#define EMPTY -1    // Define constant for empty slot
#define DELETED -2  // Define constant for deleted slot

int hashTable[SIZE];  // Array representing the hash table

// Initialize the hash table with EMPTY value
void init()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = EMPTY;  // Set each slot in hash table to EMPTY
    }
}

// Insert a value into the hash table using linear probing
void insert(int value)
{
    int key = value % SIZE;  // Calculate hash key
    int index = key;

    // Probe for the next available slot
    while (hashTable[index] != EMPTY && hashTable[index] != DELETED)
    {
        index = (index + 1) % SIZE;  // Move to the next slot
        if (index == key)  // If we loop back to the starting slot
        {
            printf("The Value %d cannot be inserted,Hash table is full.\n",value);
            return;
        }
    }
    hashTable[index] = value;  // Insert value into the available slot
}

// Delete a value from the hash table
void delete(int value)
{
    int key = value % SIZE;  // Calculate hash key
    int index = key;

    // Probe to find the value
    while (hashTable[index] != EMPTY)
    {
        if (hashTable[index] == value)  // If value found
        {
            hashTable[index] = DELETED;  // Mark it as DELETED
            printf("Deleted the value %d from index %d.\n", value, index);
            return;
        }
        else
        {
            index = (index + 1) % SIZE;  // Move to the next slot
            if (index == key)  // If we loop back to the starting slot
            {
                break;
            }
        }
    }
    printf("Value %d not found in the table.\n", value);  // Value not found
}

// Search for a value in the hash table
void search(int value)
{
    int key = value % SIZE;  // Calculate hash key
    int index = key;

    // Probe to find the value
    while (hashTable[index] != EMPTY)
    {
        if (hashTable[index] == value)  // If value found
        {
            printf("Value %d found at index %d.\n", value, index);
            return;
        }
        else
        {
            index = (index + 1) % SIZE;  // Move to the next slot
            if (index == key)  // If we loop back to the starting slot
            {
                break;
            }
        }
    }
    printf("Value %d not found in the hash table.\n", value);  // Value not found
}

// Print the contents of the hash table
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
    init();  // Initialize the hash table
    insert(0);
    insert(1);
    insert(2);
    insert(3);
    insert(12);
    insert(4);
    insert(22);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    
    print();  // Print hash table after insertion
    
    search(4);  // Search for value 4
    delete(4);  // Delete value 4
    search(4);  // Search for value 4 after deletion
    
    print();  // Print hash table after deletion

    return 0;
}
