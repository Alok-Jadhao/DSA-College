#include<stdio.h>
#include<stdlib.h>

#define V 4

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void addEdge(int adj[V][V], int i, int j) {
    adj[i][j] = 1;
    adj[j][i] = 1;
}

void display(int adj[V][V]) {
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* list[], int i, int j) {
    Node* newNode = createNode(j);
    newNode->next = list[i];
    list[i] = newNode;

    newNode = createNode(i);
    newNode->next = list[j];
    list[j] = newNode;

}

void display(Node* list[]) {
    for (int i = 0; i < V; i++)
    {
        printf("%d: ", i);
        Node* temp = list[i];
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    
}

// Main function
int main() {
  
    // Create a graph with 4 vertices and no edges
    Node* adj[V];
    for (int i = 0; i < V; i++) {
        adj[i] = NULL; // Initialize adjacency list
    }

    // Now add edges one by one
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    printf("Adjacency List Representation:\n");
    display(adj);

    return 0;
}