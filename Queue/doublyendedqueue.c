#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Check if deque is full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

// Check if deque is empty
int isEmpty() {
    return front == -1;
}

// Insert at front
void insertFront(int data) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = data;
}

// Insert at rear
void insertRear(int data) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = data;
}

// Delete from front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted element from front: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;  // Deque is now empty
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Delete from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted element from rear: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;  // Deque is now empty
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Display elements of deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Elements in deque: ");
    int i = front;
    if (front <= rear) {
        while (i <= rear)
            printf("%d ", deque[i++]);
    } else {
        while (i < MAX)
            printf("%d ", deque[i++]);
        i = 0;
        while (i <= rear)
            printf("%d ", deque[i++]);
    }
    printf("\n");
}

int main() {
    insertRear(5);
    insertRear(10);
    insertFront(15);
    display();

    deleteFront();
    display();

    insertRear(20);
    insertFront(25);
    display();

    deleteRear();
    display();

    return 0;
}
