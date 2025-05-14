#include<bits/stdc++.h>
using namespace std;

void vertexCover(vector<vector<int>>& G, vector<int> &vc) {
    int n = G.size();
    vector<pair<int, int>> edges;

    for (int u = 0; u < n; u++)
    {
        for(int v: G[u]) {
            if(u < v) {
                edges.push_back({u,v});
            }
        }
    }
    
    while (!edges.empty())
    {
        auto edge = edges.back();
        edges.pop_back();

        int u = edge.first;
        int v = edge.second;

        vc.push_back(u);
        vc.push_back(v);

        for (auto it = edges.begin(); it != edges.end();)
        {
            if(it->first == u || it->second == u || it->first == v || it->second == v) {
                it = edges.erase(it);
            } else it++;
        }
        
    }
    
    


}

int main() {
    vector<vector<int>> G = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2}
    };

    vector<int> vc;

    vertexCover(G, vc);

    for(int num: vc) cout << num << " ";
    cout << endl;

    return 0;

}

// Output:
// Vertex Cover: 0 1 2 3
// Time Complexity: O(E)
// Space Complexity: O(V + E)
// Optimal Vertex Cover: 1 2