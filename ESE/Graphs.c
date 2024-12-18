#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define V 4

// typedef struct Node
// {
//     int data;
//     struct Node* next;
// } Node;

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

// Node* createNode(int data) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// void addEdge(Node* list[], int i, int j) {
//     Node* newNode = createNode(j);
//     newNode->next = list[i];
//     list[i] = newNode;

//     newNode = createNode(i);
//     newNode->next = list[j];
//     list[j] = newNode;

// }

// void display(Node* list[]) {
//     for (int i = 0; i < V; i++)
//     {
//         printf("%d: ", i);
//         Node* temp = list[i];
//         while (temp != NULL)
//         {
//             printf("%d ", temp->data);
//             temp = temp->next;
//         }
//         printf("\n");
//     }
    
// }

void bfs(int adj[V][V], int s) {
    int queue[V], front = 0, rear = 0;

    bool visited[V] = {false};

    visited[s] = true;
    queue[rear++] = s;

    while (front < rear) { 
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < V; i++)
        {
            if(adj[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

void dfs(int adj[V][V], int s,bool visited[V]) {
    

    printf("%d ", s);
    visited[s] = true;

    for (int i = 0; i < V; i++)
    {
        if(adj[s][i] == 1 && !visited[i]) {
            dfs(adj,i, visited);
        }
    }
}




// // Main function
// int main() {
  
//     // Create a graph with 4 vertices and no edges
//     Node* adj[V];
//     for (int i = 0; i < V; i++) {
//         adj[i] = NULL; // Initialize adjacency list
//     }

//     // Now add edges one by one
//     addEdge(adj, 0, 1);
//     addEdge(adj, 0, 2);
//     addEdge(adj, 1, 2);
//     addEdge(adj, 2, 3);

//     printf("Adjacency List Representation:\n");
//     display(adj);

//     return 0;
// }
