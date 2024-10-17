#include <stdio.h>
#include <stdlib.h>

#define size 10  // Define the size of the hash table

// Define the structure for nodes in the linked list
struct node
{
    int data;           // Data to be stored in the node
    struct node *next;  // Pointer to the next node in the chain
};

// Array of pointers to struct node, used as the hash table
struct node *chain[size];

// Initialize the hash table by setting each pointer to NULL
void init()
{
    for (int i = 0; i < size; i++)
    {
        chain[i] = NULL;  // Set each slot in the hash table to NULL
    }
}

// Insert a value into the hash table
void insert(int value)
{
    // Allocate memory for a new node and set its data and next pointer
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    // Compute the hash key for the given value
    int key = value % size;

    // Insert the node at the beginning if there's no existing chain
    if (chain[key] == NULL)
    {
        chain[key] = newnode;
    }
    else
    {
        // Traverse to the end of the chain and append the new node
        struct node *temp = chain[key];
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Delete a value from the hash table
void delete(int value)
{
    int key = value % size;  // Compute the hash key for the value
    struct node *temp = chain[key];  // Start with the first node in the chain
    struct node *prev = NULL;  // Track the previous node for unlinking

    // Traverse to find the node with the given value
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the value is found, remove the node from the chain
    if (temp != NULL)
    {
        if (prev == NULL)
        {
            // If deleting the first node, update the chain head
            chain[key] = temp->next;
        }
        else
        {
            // Bypass the node to delete it from the list
            prev->next = temp->next;
        }
        free(temp);  // Free the memory of the deleted node
        printf("Node with value %d deleted.\n", value);
    }
    else
    {
        printf("The value %d you want to delete was not found\n", value);
    }
}

// Search for a value in the hash table
void search(int value)
{
    int key = value % size;  // Compute the hash key for the value
    struct node *temp = chain[key];  // Start at the head of the chain
    int flag = 0;  // Flag to indicate if value is found

    // Traverse the chain to find the value
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    // Output the result of the search
    if (flag == 1)
    {
        printf("Value %d found at key-> %d\n", value, key);
    }
    else
    {
        printf("The value %d you are searching for was not found\n", value);
    }
}

// Count the number of nodes in a specific chain
void countInChain(int key)
{
    struct node *temp = chain[key];  // Start at the head of the chain
    int count = 0;  // Initialize counter

    // Traverse the chain to count each node
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("The count in the chain is %d\n", count);
}

// Print the hash table and its chains
void print()
{
    // Traverse each index in the hash table
    for (int i = 0; i < size; i++)
    {
        struct node *temp = chain[i];  // Start at the head of the chain
        printf("chain[%d]-->", i);

        // Print each node in the chain
        while (temp)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");  // End of chain
    }
}

int main()
{
    // Initialize the hash table
    init();

    // Insert values into the hash table
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    insert(11);
    insert(12);
    insert(13);
    insert(14);
    insert(15);
    insert(16);
    insert(17);
    insert(18);
    insert(19);
    insert(20);
    insert(23);
    insert(33);

    // Print the hash table
    print();

    // Count nodes in specific chains
    countInChain(2);
    countInChain(3);
    countInChain(4);

    // Search for a specific value
    search(5);

    // Delete a value from the hash table
    delete(5);

    // Search for the deleted value to verify deletion
    search(5);

    // Count nodes in chain after deletion
    countInChain(5);

    // Print the hash table after deletion
    print();

    return 0;  // End of main function
}
