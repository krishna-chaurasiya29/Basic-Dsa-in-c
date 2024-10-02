//Descending Priority Queue
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data;
    int priority;
} Node;

Node priorityQueue[MAX];
int size = 0;

// Function to insert an element in the priority queue
void enqueue(int data, int priority) {
    if (size == MAX) {
        printf("Priority Queue is full!\n");
        return;
    }

    Node newNode;
    newNode.data = data;
    newNode.priority = priority;

    // Find the correct position to insert the new node
    int i = size - 1;
    while (i >= 0 && priorityQueue[i].priority < priority) {
        priorityQueue[i + 1] = priorityQueue[i];
        i--;
    }

    priorityQueue[i + 1] = newNode;
    size++;
    printf("Inserted %d with priority %d\n", data, priority);
}

// Function to remove the element with the highest priority
void dequeue() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Removed %d with priority %d\n", priorityQueue[0].data, priorityQueue[0].priority);
    // Shift elements to the left
    for (int i = 1; i < size; i++) {
        priorityQueue[i - 1] = priorityQueue[i];
    }

    size--;
}

// Function to display the priority queue
void display() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < size; i++) {
        printf("Data: %d, Priority: %d\n", priorityQueue[i].data, priorityQueue[i].priority);
    }
}

int main() {
    enqueue(10, 3);
    enqueue(5, 1);
    enqueue(30, 4);
    enqueue(20, 2);

    display();

    dequeue();
    display();

    return 0;
}

// This is example of descending priorityQueue