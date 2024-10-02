// Queue using linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
}Queue;

Queue * createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front,q->rear = NULL;
    return q;
}

void enqueue(Queue * q)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the data: ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    if(q->rear == NULL)
    {
        q->front = q->rear = newNode;
        q->rear=newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue *q)
{
    if(q->front==NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    Node *temp = q->front;
    q->front = q->front->next;
    if(q->front==NULL)
    {
        q->rear = NULL;
    }
    printf("the Dequed element is :-%d\n",temp);
    free(temp);
}
void display(Queue * q)
{
    Node *temp = q->front;
    if(q->front==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("Null\n");
}
void peak(Queue *q)
{
    if(q->front==NULL)
    {
        printf("Queue is empty\n");
    }
    printf("\nthe peak element is :-%d",q->rear);
}
int main()
{
    Queue *q = createQueue();
    int choice=1;
    while(choice)
    {
        printf("\nQueue Operations..\n");
        printf("1. Enqueue\n2. Dequeue\n3. peak\n4. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                enqueue(q);
                break;
            }
            case 2:
            {
                dequeue(q);
                break;
            }
            case 3:
            {
                peak(q);
                break;
            }
            case 4:
            {
                display(q);
                break;
            }
            case 5:
            {
                exit(0);
            }
            default:
            {
                printf("Wrong choice\n");
            }
        }
    }
}