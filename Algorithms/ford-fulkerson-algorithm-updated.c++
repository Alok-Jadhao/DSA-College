#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<cstring>
#include<fstream>

using namespace std;

int V;

bool dfs(int s, int t, vector<int>& parent, vector<vector<int>>& residual, vector<bool>& visited) {
    visited[s] = true;
    if(s == t) return true;

    for (int v = 0; v < V; v++)
    {
        if(!visited[v] && residual[s][v] > 0) {
            parent[v] = s;
            if (dfs(v,t,parent, residual, visited)) return true;
        }
    }
    return false;
}

int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    vector<vector<int>> residual = graph;

    vector<int> parent(V, -1);
    int maxFlow = 0;

    while (true)
    {
        vector<bool> visited(V, false);
        fill(parent.begin(), parent.end(), -1);

        if(!dfs(s,t, parent, residual, visited)) break;

        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, residual[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
        }

        maxFlow += path_flow;
    }
    return maxFlow;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    inputFile >> V;
    vector<vector<int>> graph(V, vector<int>(V, 0));

    int E;
    inputFile >> E;

    for (int i = 0; i < E; i++) {
        int u, v, capacity;
        inputFile >> u >> v >> capacity;
        graph[u][v] = capacity;
    }

    int source, sink;
    inputFile >> source >> sink;
    inputFile.close();

    int maxFlow = fordFulkerson(graph, source, sink);
    cout << "The maximum possible flow from vertex " << source << " to vertex " << sink << " is " << maxFlow << ".\n";

    return 0;
}