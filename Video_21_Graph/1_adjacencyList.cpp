#include <bits/stdc++.h>
using namespace std;
// Algorithm:
// 1. Create an adjacency list for V vertices.
// 2. Read every edge (u, v).
// 3. Add v to adj[u] and u to adj[v].
// 4. Return the adjacency list.

vector<vector<int>> solve(int V, vector<pair<int, int>>& edges) {
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

    vector<vector<int>> adj = solve(V, edges);

    for (int i = 0; i < V; i++) {
        cout << i << ": ";

        for (int neighbour : adj[i]) {
            cout << neighbour << " ";
        }

        cout << '\n';
    }

    return 0;
}