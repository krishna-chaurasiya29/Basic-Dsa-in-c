#include <stdio.h>
#include <stdlib.h>
#define size 7
struct node
{
    int data;
    struct node *next;
};
struct node *chain[size];
void init()
{
    int i;
    for (i = 0; i < size; i++)
        chain[i] = NULL;
}
void insert(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    int key = value % size;
    if (chain[key] == NULL)
        chain[key] = newNode;
    // collision
    else
    {
        struct node *temp = chain[key];
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete(int value)
{
    int key = value % size;
    struct node *temp = chain[key];
    struct node *prev = NULL;

    // Search for the node with the given value
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    // If value is found
    if (temp != NULL)
    {
        if (prev == NULL)
        {
            // If the node to delete is the first node in the chain
            chain[key] = temp->next;
        }
        else
        {
            // If the node is in the middle or end
            prev->next = temp->next;
        }
        free(temp);
        printf("Node with value %d deleted.\n", value);
    }
    else
    {
        printf("Node with value %d not found.\n", value);
    }
}

int search(int value)
{
    int key = value % size;
    struct node *temp = chain[key];
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return 1; // Found
        }
        temp = temp->next;
    }
    return 0; // Not found
}

int countInChain(int key)
{
    struct node *temp = chain[key];
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void print()
{
    int i;
    for (i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->", i);
        while (temp)
        {
            printf("%d -->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
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
    print();
    return 0;
}