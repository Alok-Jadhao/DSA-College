#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    int arr[MAX_SIZE];
    int front;
    int rear;
} PriorityQueue;

void initializePQueue(PriorityQueue *queue)
{
    queue->front = 0;
    queue->rear = -1;
}

bool isEmpty(PriorityQueue *queue)
{
    return (queue->front > queue->rear);
}

bool isFull(PriorityQueue *queue)
{
    return (queue->rear > MAX_SIZE - 1);
}

void enqueue(PriorityQueue *queue, int data)
{
    if (isFull(queue))
    {
        printf("Queue is Full\n");
        return;
    }

    int i;
    queue->arr[++queue->rear] = data;

    // Sort the queue in ascending order
    for (i = queue->rear; i > queue->front && queue->arr[i] < queue->arr[i - 1]; i--)
    {
        int temp = queue->arr[i];
        queue->arr[i] = queue->arr[i - 1];
        queue->arr[i - 1] = temp;
    }
}

int dequeue(PriorityQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return -1;
    }

    int element = queue->arr[queue->front];
    queue->front++;

    if (isEmpty(queue))
    {
        initializePQueue(queue);
    }

    return element;
}

void printQueue(PriorityQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return;
    }

    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int peek(PriorityQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    return queue->arr[queue->front];
}

int main()
{
    PriorityQueue queue;
    initializePQueue(&queue);

    while (1)
    {
        printf("1. Insert\n2. Delete\n3. Peek\n4. Print Queue \n5.Exit\n");
        int choice;
        printf("\n");
        scanf("%d", &choice);

        if (choice == 5)
        {
            break;
        }

        int data;
        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            printf("\n");
            enqueue(&queue, data);
            break;
        case 2:
            printf("Deleted element is %d\n", dequeue(&queue));
            printf("\n");
            break;
        case 3:
            printf("Peek element is %d\n", peek(&queue));
            printf("\n");
            break;
        case 4:
            printQueue(&queue);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
