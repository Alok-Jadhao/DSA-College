#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 100

// Define a structure for the stack
typedef struct {
    // Array to store stack elements
    int arr[MAX_SIZE];  
    // Index of the top element in the stack
    int top;        
} Stack;

// Function to initialize the stack
void initialize(Stack *stack) {
    // Set top index to -1 to indicate an empty stack
    stack->top = -1;  
}

// Function to check if the stack is empty
bool isEmpty(Stack *stack) {
    // If top is -1, the stack is empty
    return stack->top == -1;  
}

// Function to check if the stack is full
bool isFull(Stack *stack) {
    // If top is MAX_SIZE - 1, the stack is full
    return stack->top == MAX_SIZE - 1;  
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    // Check for stack overflow
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    // Increment top and add the value to the top of the stack
    stack->arr[++stack->top] = value;
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    // Check for stack underflow
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    // Return the top element 
    int popped = stack->arr[stack->top];
    // decrement top pointer
    stack->top--;
    printf("Popped %d from the stack\n", popped);
    // return the popped element
    return popped;
}

// Function to peek the top element of the stack
int peek(Stack *stack) {
    // Check if the stack is empty
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    // Return the top element without removing it
    return stack->arr[stack->top];
}


struct Node {
    int data;
    struct Node* next;
};

struct List {
    struct Node* head;
};

struct Graph {
    int vertices;
    struct List* array;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// create graph
// Create graph
struct Graph* createGraph(int V) {
    struct Graph* newGraph = (struct Graph*)malloc(sizeof(struct Graph));
    newGraph->vertices = V;
    newGraph->array = (struct List*)malloc(V * sizeof(struct List)); // Corrected line

    for (int i = 0; i < V; i++) {
        newGraph->array[i].head = NULL;
    }

    return newGraph;
}



void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// void DFS(struct Graph* graph, int root, bool visited[]) {


// }

// function to print the adjacency list.
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        struct Node* temp = graph->array[i].head;
        printf("\n Adjacency list of vertex %d\n head ", i);
        while (temp) {
            printf("-> %d", temp->data);
            temp = temp->next;
        }
    }
}

void DFS(struct Graph* graph, int root) {
    bool visited[MAX_SIZE] = {false};
    Stack stack;
    initialize(&stack);

    push(&stack, root);

    while (!isEmpty(&stack)) {
        int current = pop(&stack);

        if (!visited[current]) {
            printf("Visited %d\n", current);
            visited[current] = true;
        }

        // Push all unvisited neighbors onto the stack
        struct Node* temp = graph->array[current].head;
        while (temp != NULL) {
            if (!visited[temp->data]) {
                push(&stack, temp->data);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int V;
    printf("Enter no. of vertices: ");
    scanf("%d", &V);
    struct Graph* graph = createGraph(V);

    // dynamically add vertices.
    
    while(1) {
        int src, dest;
        printf("Enter the source and destination vertices: or -1 -1 to exit: ");
        scanf("%d %d", &src, &dest);
        if(src == -1 && dest == -1) {
            break;
        }
        addEdge(graph, src, dest);
    }

    // print the adjacency list.
    printGraph(graph);

    printf("Enter the root: ");
    int root;
    scanf("%d", &root);
    
    // DFS traversal
    DFS(graph, root);
}



