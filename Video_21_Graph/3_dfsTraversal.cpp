#include <bits/stdc++.h>
using namespace std;
// Algorithm:
// 1. Create an adjacency list for V vertices.
// 2. Add both directions for every undirected edge.
// 3. Start DFS from vertex 0.
// 4. Mark the current vertex visited and add it to the traversal.
// 5. Recursively visit every unvisited neighbour.
// 6. Return the DFS traversal.

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& ls) {
    vis[node] = true;
    ls.push_back(node);

    for (auto& neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, adj, vis, ls);
        }
    }
}

vector<int> solve(int V, vector<vector<int>>& adj) {
    vector<bool> vis(V, false);
    vector<int> ls;

    if (V > 0) {
        dfs(0, adj, vis, ls);
    }

    return ls;
}

vector<vector<int>> generateAdj(int V, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(V);

    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
    // TC = O(E)
    // SC = O(2E)
}



int main() {
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> edges(E);

    for (int i = 0; i < E; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<vector<int>> adj = generateAdj(V,edges);
    vector<int> result = solve(V, adj);

    for (int node : result) {
        cout << node << " ";
    }
    cout << '\n';
    return 0;
}