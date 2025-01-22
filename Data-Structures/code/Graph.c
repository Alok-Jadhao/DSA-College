#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int adj[MAX][MAX];
    int vertices;
} Graph;

typedef struct {
    int items[MAX];
    int top;
} Stack;

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmptyStack(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (s->top == MAX - 1)
        return;
    s->items[++s->top] = value;
}

int pop(Stack* s) {
    if (isEmptyStack(s))
        return -1;
    return s->items[s->top--];
}

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmptyQueue(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmptyQueue(q))
        return -1;
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void bfs(Graph* g, int startVertex) {
    Queue q;
    initQueue(&q);
    int visited[MAX] = {0};

    printf("BFS Traversal: ");
    enqueue(&q, startVertex);
    visited[startVertex] = 1;

    while (!isEmptyQueue(&q)) {
        int u = dequeue(&q);
        printf("%d ", u);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adj[u][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

void dfs(Graph* g, int u, int visited[], int* time, int in[], int out[]) {
    Stack s;
    initStack(&s);
    push(&s, u);
    
    printf("DFS Traversal: ");

    while (!isEmptyStack(&s)) {
        int u = pop(&s);

        if (!visited[u]) {
            visited[u] = 1;
            in[u] = ++(*time);
            printf("%d ", u);

            for (int i = g->vertices - 1; i >= 0; i--) {
                if (g->adj[u][i] && !visited[i]) {
                    push(&s, i);
                }
            }

            out[u] = ++(*time);
        }
    }

    printf("\n");
}

int main() {
    Graph g;
    int vertices, u, v, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);

    printf("Enter edges (u v), input -1 -1 to stop:\n");
    while (1) {
        scanf("%d %d", &u, &v);
        if (u == -1 && v == -1)
            break;
        addEdge(&g, u, v);
    }

    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &startVertex);

    bfs(&g, startVertex);

    int visited[MAX] = {0};
    int in[MAX] = {0}, out[MAX] = {0};
    int time = 0;

    dfs(&g, startVertex, visited, &time, in, out);

    printf("In-time and Out-time of vertices:\n");
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: In-time = %d, Out-time = %d\n", i, in[i], out[i]);
    }

    return 0;
}
