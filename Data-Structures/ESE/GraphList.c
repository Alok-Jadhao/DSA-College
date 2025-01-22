#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

// Queue structure for BFS
typedef struct Queue {
    int* items;
    int front;
    int rear;
    int max_size;
} Queue;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the adjacency list
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to create a queue
Queue* createQueue(int max_size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->items = (int*)malloc(max_size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->max_size = max_size;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to enqueue
void enqueue(Queue* q, int value) {
    if (q->rear == q->max_size - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

// Function to dequeue
int dequeue(Queue* q) {
    if (isEmpty(q))
        return -1;
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Breadth-First Search
void BFS(Graph* graph, int startVertex) {
    Queue* q = createQueue(graph->numVertices);

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("Breadth-First Search Traversal:\n");
    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Depth-First Search
void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);

    printf("Adjacency List Representation of the Graph:\n");
    printGraph(graph);

    printf("\nPerforming BFS starting from vertex 0:\n");
    BFS(graph, 0);

    // Reset visited array for DFS
    for (int i = 0; i < vertices; i++) {
        graph->visited[i] = 0;
    }

    printf("\nPerforming DFS starting from vertex 0:\n");
    DFS(graph, 0);
    printf("\n");

    return 0;
}

