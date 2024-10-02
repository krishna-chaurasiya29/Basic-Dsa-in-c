#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the queue

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CircularQueue;

// Function to initialize the queue
void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(CircularQueue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

// Function to check if the queue is empty
int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

// Function to add an element to the queue (enqueue)
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0; // Initialize front when first element is enqueued
    }

    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    printf("Inserted %d\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int value = q->data[q->front];
    if (q->front == q->rear) {
        // If the queue has only one element, reset the queue
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    printf("Removed %d\n", value);
    return value;
}

// Function to display the queue
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->data[q->rear]);
}

int main() {
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 60);
    enqueue(&q, 70);

    display(&q);

    return 0;
}
