#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, adj, vis);
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<int> adj[n];
    // create adj list
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && isConnected[i][j] == 1)
                adj[i].push_back(j);
        }
    }

    int count = 0;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis);
            count++;
        }
    }
    return count;
}
int main()
{
    return 0;
}