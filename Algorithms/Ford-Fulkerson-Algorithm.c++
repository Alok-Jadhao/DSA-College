#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <cstring>

using namespace std;

// Number of vertices in the graph. For demonstration, we will assume it is set by input.
// For a real experiment with at least 20 vertices, ensure the input graph has >= 20 nodes.
int V;

// A DFS based function that finds an augmenting path and stores the path in the parent vector.
// Returns true if a path from source 's' to sink 't' is found in the residual graph.
bool dfs(int s, int t, vector<int>& parent, vector<vector<int>>& residual, vector<bool>& visited) {
    visited[s] = true;
    if (s == t) return true;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && residual[s][v] > 0) {  // if not yet visited and there's available capacity
            parent[v] = s;
            if (dfs(v, t, parent, residual, visited))
                return true;
        }
    }
    return false;
}

// Ford-Fulkerson algorithm to compute maximum flow from source 's' to sink 't'
int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    // Create a residual graph and fill with initial capacities
    vector<vector<int>> residual = graph;
    
    // This vector is filled by DFS to store the path
    vector<int> parent(V, -1);
    int max_flow = 0;  // There is no flow initially

    // Augment the flow while there is an augmenting path from source to sink
    while (true) {
        vector<bool> visited(V, false);
        fill(parent.begin(), parent.end(), -1);
        
        // Use DFS to find if an augmenting path exists
        if (!dfs(s, t, parent, residual, visited))
            break; // No more augmenting paths found

        // Find the minimum residual capacity of the edges along the path filled by DFS
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, residual[u][v]);
        }

        // Update the residual capacities of the edges and reverse edges along the path
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    // Example: Read number of vertices
    cout << "Enter number of vertices: ";
    cin >> V;

    // Create a graph represented by a 2D vector (adjacency matrix)
    vector<vector<int>> graph(V, vector<int>(V, 0));

    // Read number of edges
    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter each edge in the format: <source> <destination> <capacity>\n";
    for (int i = 0; i < E; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph[u][v] = capacity; // For a directed graph, assign capacity to edge (u,v)
    }

    int source, sink;
    cout << "Enter source vertex: ";
    cin >> source;
    cout << "Enter sink vertex: ";
    cin >> sink;

    int maxFlow = fordFulkerson(graph, source, sink);
    cout << "The maximum possible flow from vertex " << source << " to vertex " << sink << " is " << maxFlow << ".\n";

    return 0;
}
