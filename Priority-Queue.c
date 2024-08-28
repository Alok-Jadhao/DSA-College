#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

void initializeQueue(PriorityQueue *queue) {
    queue->size = 0;
}

int isEmpty(PriorityQueue *queue) {
    return queue->size == 0;
}

int isFull(PriorityQueue *queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(PriorityQueue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }

    // Insert the element at the end
    queue->data[queue->size] = element;
    queue->size++;

    // Use insertion sort to maintain the priority order
    int i = queue->size - 1;
    while (i > 0 && queue->data[i] > queue->data[i - 1]) {
        int temp = queue->data[i];
        queue->data[i] = queue->data[i - 1];
        queue->data[i - 1] = temp;
        i--;
    }
}

int dequeue(PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int element = queue->data[0];
    queue->size--;
    return element;
}

void printQueue(PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    PriorityQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 2);
    enqueue(&queue, 8);

    printQueue(&queue);

    int dequeuedElement = dequeue(&queue);
    printf("Dequeued element: %d\n", dequeuedElement);

    printQueue(&queue);

    return 0;
}
