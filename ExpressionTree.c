// Create an expression tree from a given preorder expression traversal

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char data;
    struct Node* left;
    struct Node* right;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->next = NULL;
    return newNode;
}


void inorderTraversal(Node* root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}

void push(Node* x) {
    if(head==NULL) {
        head = x;
        
    }
    else
    {
        x->next = head;
        head = x;
        
    }
    printf("Pushed: %c\n", x->data);
}

Node* pop()
{
    Node* p = head;
    head = head->next;
    printf("Popped: %c\n", p->data);
    return p;
}


Node* createExpressionTree(char* exp) {
    Node *x,*y,*z;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            z = createNode(exp[i]);
            x = pop();
            y = pop();
            z->left = x;
            z->right = y;
            push(z);
        }
        else {
            z = createNode(exp[i]);
            push(z);
        }
    }
    return z;
    
}

void reverse(char* str) {

    int first = 0;
    int last = strlen(str) - 1;
    char temp;


    while (first < last) {
        

        temp = str[first];
        str[first] = str[last];
        str[last] = temp;

    
        first++;
        last--;
    }
}


int main() {
    Node* root = NULL;
    char exp[50];
    printf("Enter the expression: ");
    scanf("%s", exp);
    reverse(exp);
    root = createExpressionTree(exp);
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    
}