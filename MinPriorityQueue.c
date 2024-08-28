#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int size;
    int front;
    int rear;

} PriorityQueue;

PriorityQueue intitializePQueue(PriorityQueue queue) {
    queue.size = 0;
    queue.front = -1;
    queue.rear = -1;
    return queue;
}

bool isEmpty(PriorityQueue queue) {
    if(queue.front > queue.rear) {
        return true;
    }

    return false;
}

bool isFull(PriorityQueue* queue) {
    if(queue->rear > MAX_SIZE-1) {
        return true;
    }
    return false;
}

int dequeue(PriorityQueue queue) {
    if(isEmpty(queue)) {
        printf("Queue is Empty");
        return -1;
    }

    if(queue.front == queue.rear) {
        queue = intitializePQueue(queue);
    }

    int element = queue.arr[queue.front];
    queue.size--;
    queue.front++;
    return element;
}

void enqueue(PriorityQueue* queue, int data) {
    if(isFull(queue)) {
        printf("Queue is Full");
        return;
    }
    if(queue->front == -1 ) {
        queue->front = 0;
    }
    queue->arr[queue->rear] = data;

    // insertion sort.
    int i = queue->rear;
    while(i > queue->front && queue->arr[i] < queue->arr[i-1]) {
        int temp = queue->arr[i];
        queue->arr[i] = queue->arr[i-1];
        queue->arr[i] = temp;
        i--;
    }
    
}

int peek(PriorityQueue queue) {
    return queue.arr[queue.front];
}

int main() {
    // Menu driven program for Min Priority Queue with insert and delete operation
    PriorityQueue queue = intitializePQueue(queue);
    while(1) {
        printf("1. Insert\n2. Delete\n3. Peek\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        if(choice == 4) {
            break;
        }
        int data;
        switch(choice) {
            case 1:
                
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 2:
                printf("Deleted element is %d\n", dequeue(queue));
                break;
            case 3:
                printf("Peek element is %d\n", peek(queue));
                break;
            default:
                printf("Invalid Choice\n");   
        }
    }
    return 0;
}