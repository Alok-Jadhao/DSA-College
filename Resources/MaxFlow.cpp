#include<bits/stdc++.h>
using namespace std;

int V;

bool dfs(int s, int t, vector<int>& parent, vector<vector<int>>& residual, vector<bool>& visited) {
    visited[s] = true;
    if(s == t) return true;

    for (int v = 0; v < V; v++)
    {
        if(!visited[v] && residual[s][v] > 0) {
            parent[v] = s;
            if(dfs(v, t, parent, residual, visited))  return true;
        }
    }
    return false;
}

int maxFlow(vector<vector<int>>& graph, int s, int t) {
    vector<vector<int>> residual = graph;

    vector<int> parent(V, -1);
    int maxFlow = 0;

    while (true)
    {
        vector<bool> visited(V, false);
        
        if(!dfs(s, t, parent, residual, visited)) break;

        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {
            path_flow = min(path_flow, residual[parent[v]][v]);
        }
        
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
        }
        maxFlow += path_flow;
    }
    return maxFlow;
}

int main() {


    return 0;
}