#include<bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int i) {
        return (parent[i] == i) ? i : parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int p1 = find(i);
        int p2 = find(j);

        if(p1 == p2) return;
        else {
            parent[j] = i;
        }
    }
};

bool comparator(vector<int>& a, vector<int> &b) {
    return a[2] < b[2];
}

int kruskalsMST(int V, vector<vector<int>>& edges) {
    int cost = 0, count = 0; // count = no. of edges

    sort(edges.begin(), edges.end(), comparator);

    DSU dsu(V);

    for(auto &e: edges) {
        int x = e[0], y = e[1], wt = e[2];
        if(dsu.find(x) != dsu.find(y)) {
            dsu.unite(x, y);
            cost += wt;
            if(++count == V-1) break;
        }
    }

    return cost;
}

// int main() {
//     // An edge contains, weight, source and destination
//     vector<vector<int>> edges = {
//         {0, 1, 10}, {1, 3, 15}, {2, 3, 4}, {2, 0, 6}, {0, 3, 5}
//     };
    
//     cout<<kruskalsMST(4, edges);
    
//     return 0;
// }


// Prims Algorithm
int minKey(vector<int> &key, vector<bool> &mstSet) {
    int min = INT_MAX, minIdx;

    for (int v = 0; v < mstSet.size(); v++)
    {
        if(mstSet[v] == false && key[v] < min) {
            min = key[v];
            minIdx = v;
        }
    }
    return minIdx;
}

void printMST(vector<int> &parent, vector<vector<int>> &graph) {
    cout << "Edge\tWeight\n";
    for (int i = 1; i < graph.size(); i++)
    {
        cout << parent[i] << " - " << i << "\t" << graph[parent[i]][i] << " \n";
    }
    
}

void primMST(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> parent(V);
    vector<int> key(V);
    vector<bool> mstSET(V);

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX, mstSET[i] = false;
    }
    key[0]= 0;

    parent[0] = -1;

    for (int count = 0; count < V-1; count++)
    {
        int u = minKey(key, mstSET);
        mstSET[u] = true;

        for (int v = 0; v < V; v++)
        {
            if(graph[u][v] && mstSET[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
        
    }
    printMST(parent, graph);
    
}





int main() {
    vector<vector<int>> graph = { { 0, 2, 0, 6, 0 },
                              { 2, 0, 3, 8, 5 },
                              { 0, 3, 0, 0, 7 },
                              { 6, 8, 0, 0, 9 },
                              { 0, 5, 7, 9, 0 } };

  // Print the solution
  primMST(graph);

  return 0;
}