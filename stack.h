#include<stdio.h>
#include<stdbool.h>

struct stack {
    int top = -1;
    int arr[100];

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top = 99;
    }

    void push(int x) {
        if(isFull()) {
            printf("Stack is full\n");
            return;
        } else {
            top++;
            arr[top] = x;
        }
    }

    int pop() {
        if(isEmpty()) {
            printf("Stack is empty\n");
            return -1;
        } else {
            return arr[top--];
        }
    }
};