#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> constructAdj(vector<vector<int>> edges, int V) {
    vector<vector<vector<int>>> adj(V);
    
    for(auto &edge: edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    return adj;
}

vector<int> dijkstra(vector<vector<int>>& graph, int src, int V) {
    // create adjacency list
    vector<vector<vector<int>>> adj = constructAdj(graph, V);

    // priority queue.
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    vector<int> dist(V, INT_MAX);

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top()[1];
        pq.pop();

        for(auto edge: adj[u]) {
            int  v = edge[0];
            int wt = edge[1];

            if(dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
    
}

vector<int> bellmanFord(vector<vector<int>>& edges, int src, int V) {
    vector<int> dist(V, 1e8);

    dist[src] = 0;

    for (int i = 0; i < V; i++) // bellman till V-1. Last loop is for checking negative cycles.
    {
        for(vector<int> edge: edges) {
            int u = edge[0];
            int v= edge[1];
            int wt = edge[2];

            if(dist[u] != 1e8 && dist[v] > dist[u] + wt) {
                if(i == V-1) return {-1};

                dist[v] = dist[u] + wt;
            }
        }
    }
    

    return dist;
}

int main() {
    // Number of vertices in the graph
    int V = 5;

    // Edge list representation: {source, destination, weight}
    vector<vector<int>> edges = {
        {1, 3, 2}, 
        {4, 3, -1},
        {2, 4, 1}, 
        {1, 2, 1},
        {0, 1, 5} 
    };

    // Define the source vertex
    int src = 0;

    // Run Bellman-Ford algorithm to get shortest paths from src
    vector<int> ans = bellmanFord(edges, src, V);

    // Output the shortest distances from src to all vertices
    for (int dist : ans) 
        cout << dist << " ";

    return 0; 
}