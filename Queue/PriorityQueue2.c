#include <stdio.h>

#define MAX 100 // Maximum size of the priority queue

typedef struct {
    int data[MAX];
    int size;
} PriorityQueue;

// Function to initialize the queue
void init(PriorityQueue *pq) {
    pq->size = 0;
}

// Function to insert an element while maintaining ascending order
void enqueue(PriorityQueue *pq, int item) {
    if (pq->size == MAX) {
        printf("Queue is full\n");
        return;
    }

    // Insert item in the correct position to keep array sorted
    int i = pq->size - 1;
    while (i >= 0 && pq->data[i] > item) {
        pq->data[i + 1] = pq->data[i]; // Shift elements to the right
        i--;
    }

    // Place the new item at the correct position
    pq->data[i + 1] = item;
    pq->size++;
}

// Function to remove and return the smallest element (front of the queue)
int dequeue(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Queue is empty\n");
        return -1; // Return -1 to indicate the queue is empty
    }

    // The smallest element is at the front (index 0)
    int smallest = pq->data[0];

    // Shift all elements to the left to remove the front
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
    }
    pq->size--;

    return smallest;
}

// Function to check if the queue is empty
int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

// Main function to test the priority queue
int main() {
    PriorityQueue pq;
    init(&pq);

    // Enqueue elements
    enqueue(&pq, 3);
    enqueue(&pq, 1);
    enqueue(&pq, 2);

    // Dequeue elements
    printf("Dequeued: %d\n", dequeue(&pq)); // Outputs 1
    printf("Dequeued: %d\n", dequeue(&pq)); // Outputs 2
    printf("Dequeued: %d\n", dequeue(&pq)); // Outputs 3

    return 0;
}

/*
Here the example of Ascending order
we insert the element in such a way that they are inserted in always sorted order or we can do 
anoter thing that while removing we can apply the condition and can remove the shortest element

In priority queue we keep one variable as size which fuction is just to store the length of the queue
if element is inserted then it will be incremented by one and vice versa

in structure variable we also have one data vaiable define by max size which is array which stores the element
in the array 
-------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Traversal of the enqueue operation
when we want to insert an element in the queue we have to insert in correct position so that queue reamins sorted
in ascend order. This requires shifting of the element to the right if they are larger then the element being inseretd

lets assume that we have to add item =2 in the queue currently having [1, 3, 5] as data
hence the size (pq->size) of the queue is 3 
for starting at the last element we will assing variable i as ( i=pq->size-1) therefore it will stroe as 2 in i

Therefore we want to insert item=2 into the correct position 
therefore will will start comparing form last i=2 with item =2 

the item present at ( pq -> data[2]=5 ) Since 5 > 2, we need to shift this element to the right to make space for 2.
Move pq->data[2] to pq->data[3] (next position).
Now, the array looks like this:[1, 3, 5, 5]
Decrement i=1 to continue comparing with previous element

now comparing the index=1 with item =2 pq->data[1] = 3. Since 3 > 2, we need to shift this element to the right as well.
Move pq->data[1] to pq->data[2] (next position).
Now, the array looks like this:[1, 3, 3, 5]
Decrement i = 0 to continue comparing with the previous element.

Compare the next element (index i = 0) with item = 2. pq->data[0] = 1
Since 1 < 2, we do not need to shift this element because 2 should come after 1.
Now that we have found the correct position for item = 2:

i = 0, meaning the new element should be placed at index i + 1 = 1.
Action:
Place 2 in pq->data[1].
[1, 2, 3, 5]
Then finally increasing the size by one


-------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Traversal of the dequeue operation
When it comes to dequeue operation we just have to remove the first element from the array as the array
is already in sorted order we just have to reverse the step we had perform in the enquee opertaion in this
we would be doing     // Shift all elements to the left to remove the front
                        for (int i = 0; i < pq->size - 1; i++) {
                            pq->data[i] = pq->data[i + 1];
                        }
we are assingning index=2 item to index =1 similarly index=3 to index=2 and continues and last we are decreasing 
the size by one.
*/