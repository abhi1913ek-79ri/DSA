#include <bits/stdc++.h>
using namespace std;
// Undirected graph
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &nodeCnt, int &degSum)
{
    vis[node] = 1;
    nodeCnt++;
    degSum += adj[node].size();
    for (auto &nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, adj, vis, nodeCnt, degSum);
        }
    }
}
int countCompleteComponents(int n, vector<vector<int>> &edges)
{
    int cnt = 0;
    vector<int> vis(n, 0);
    vector<vector<int>> adj(n);
    for(auto& e : edges){
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            int nodeCnt = 0;
            int degSum = 0;
            dfs(i,adj,vis,nodeCnt,degSum);
            int edgeCnt  = degSum/2;
            if(edgeCnt == (nodeCnt*(nodeCnt-1))/2) cnt++;
        }
    }

    return cnt;
    // TC = O(V+E)
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n;
        cin >> m;

        vector<vector<int>> edges(m, vector<int>(2));

        for (int i = 0; i < m; i++)
        {
            cin >> edges[i][0] >> edges[i][1];
        }

        cout << countCompleteComponents(n, edges) << endl;
    }

    return 0;
}

// ALGO 
/*
step 1 : Build Graph ie , adjacency list
step 2 : declare visited 
step 3 : for every node (loop)
step 4 :  dfs(node , vis, adj ,other states)
step 5 : collect information generate answers
here collect informarion : 
like node count , edge count , for every component , and if( edge == node*(node-1)/2)
*/