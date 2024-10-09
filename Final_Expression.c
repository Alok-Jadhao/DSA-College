#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Stack
{
    Node *treeNode;
    struct Stack *next;
} Stack;

Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void push(Stack **top, Node *treeNode)
{
    Stack *newStackNode = (Stack *)malloc(sizeof(Stack));
    newStackNode->treeNode = treeNode;
    newStackNode->next = *top;
    *top = newStackNode;
    printf("Pushed %c onto the stack\n", treeNode->data);
}

Node *pop(Stack **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty!\n");
        return NULL;
    }
    Stack *temp = *top;
    Node *poppedNode = temp->treeNode;
    *top = (*top)->next;
    free(temp);
    printf("Popped %c from the stack\n", poppedNode->data);
    return poppedNode;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node *buildExpressionTree(char *postfix)
{
    Stack *stack = NULL;

    for (int i = 0; i < strlen(postfix); i++)
    {
        char currentChar = postfix[i];

        if (isdigit(currentChar))
        {
            Node *operandNode = createNode(currentChar);
            push(&stack, operandNode);
        }
        else if (isOperator(currentChar))
        {
            Node *operatorNode = createNode(currentChar);
            Node *rightNode = pop(&stack);
            Node *leftNode = pop(&stack);

            operatorNode->left = leftNode;
            operatorNode->right = rightNode;

            push(&stack, operatorNode);
        }
    }

    return pop(&stack);
}

int evaluatePostfix(char *postfix)
{
    Stack *stack = NULL;

    for (int i = 0; i < strlen(postfix); i++)
    {
        char current = postfix[i];

        if (isdigit(current))
        {
            push(&stack, createNode(current));
        }
        else
        {
            int right = pop(&stack)->data - '0';
            int left = pop(&stack)->data - '0';

            switch (current)
            {
            case '+':
                push(&stack, createNode(left + right + '0'));
                break;
            case '-':
                push(&stack, createNode(left - right + '0'));
                break;
            case '*':
                push(&stack, createNode(left * right + '0'));
                break;
            case '/':
                push(&stack, createNode(left / right + '0'));
                break;
            }
        }
    }

    return pop(&stack)->data - '0';
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

int main()
{
    char postfixExpression[100];

    printf("Enter a postfix expression (e.g. 23+5*): ");
    scanf("%s", postfixExpression);

    Node *root = buildExpressionTree(postfixExpression);

    printf("\nInorder Traversal of the Expression Tree: ");
    inorderTraversal(root);
    printf("\n");

    int result = evaluatePostfix(postfixExpression);
    printf("Result of the postfix expression: %d\n", result);

    return 0;
}
