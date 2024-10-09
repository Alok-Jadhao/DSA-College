#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum size of the stack

// Stack structure definition
struct Stack
{
    int top;
    int items[MAX];
};

// Function to initialize the stack
void initStack(struct Stack *s)
{
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack s)
{
    return s.top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack s)
{
    return s.top == MAX - 1;
}

// Function to push an element onto the stack
struct Stack push(struct Stack s, int item)
{
    if (isFull(s))
    {
        printf("Stack overflow! Cannot push %d\n", item);
        return s;
    }
    s.items[++s.top] = item;
    printf("Pushed %d to the stack.\n", item);
    return s;
}

// Function to pop an element from the stack
struct Stack pop(struct Stack s, int *item)
{
    if (isEmpty(s))
    {
        printf("Stack underflow! Cannot pop from the stack.\n");
        *item = -1; // Set item to -1 to indicate stack underflow
        return s;
    }
    *item = s.items[s.top--];
    return s;
}

// Function to peek the top element of the stack
int peek(struct Stack s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty! Cannot peek.\n");
        return -1;
    }
    return s.items[s.top];
}

// Function to display the stack
void display(struct Stack s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s.top; i++)
    {
        printf("%d ", s.items[i]);
    }
    printf("\n");
}
