#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int front, rear;
} Queue;

Queue initializeQueue()
{
    Queue queue;
    queue.front = -1;
    queue.rear = -1;
}

int isEmpty(Queue queue)
{
    return queue.front == -1;
}

// Empty alternative approach
/*
int isEmpty(Queue queue) {
    return queue.rear < queue.front;
}
*/

int isFull(Queue queue)
{
    return queue.rear == MAX_SIZE - 1;
}

Queue enqueue(Queue queue, int element)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
        return queue;
    }

    if (isEmpty(queue))
    {
        queue.front = 0;
    }
    queue.data[++queue.rear] = element;
    return queue;
}

int dequeue(Queue queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }

    int element = queue.data[queue.front];
    if (queue.front == queue.rear)
    {
        queue = initializeQueue();
    }
    else
    {
        queue.front++;
    }

    return element;
}
