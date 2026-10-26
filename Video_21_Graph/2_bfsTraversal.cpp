#include <bits/stdc++.h>
using namespace std;

// Algorithm:
// 1. Create an adjacency list for V vertices.
// 2. Add both directions for every undirected edge.
// 3. Start BFS from vertex 0 using a queue.
// 4. Mark vertices visited when pushing them into the queue.
// 5. Process neighbours level by level and return the traversal.

vector<int> solve(int V, vector<vector<int>>& adj) {
    vector<int> visited(V, 0);
    vector<int> bfs;
    queue<int> q;

    if (V == 0) return bfs;

    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        bfs.push_back(node);

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }

    return bfs;
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

    auto adj = generateAdj(V,edges);
    vector<int> result = solve(V, adj);

    for (int node : result) {
        cout << node << " ";
    }

    cout << '\n';

    return 0;
}