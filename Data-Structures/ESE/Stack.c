#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

typedef struct Stack
{
    int top;
    char items[MAX];
}Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

void push(Stack* stack, char data) {
    if(isFull(stack)) {
        printf("Stack is full.");
        return;
    }

    stack->items[++stack->top] = data;
}

char pop(Stack* stack) {
    if(isEmpty(stack)) {
        printf("Stack empty.");
        return '\0';
    }

    return stack->items[stack->top--];
}

char peek(Stack* stack) {
    if(isEmpty(stack)) {
        return '\0';
    }

    return stack->items[stack->top];
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initStack(&stack);
    int i, j = 0;

    for (i = 0; infix != '\0'; i++)
    {
        char ch = infix[i];

        if(isalnum(ch)) {
            postfix[j++] = ch;
        }

        else if(ch == '(') {
            push(&stack, ch);
        }

        else if(ch == ')') {
            while(!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        }

        else if(isOperator(ch)) {
            if(!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(&stack)) 
    {
        /* code */
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';

}



void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n/2; i++)
    {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
    
}

void infixToPrefix(char* infix, char* prefix) {
    reverse(prefix);

    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    char postfix[MAX];
    infixToPostfix(infix, postfix);
    strcpy(prefix, postfix);
    reverse(prefix);
}