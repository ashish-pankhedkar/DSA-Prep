#include <bits/stdc++.h>
using namespace std;
bool dfs(int src, vector<int> adj[], int vis[], int pathVis[])
{
    vis[src] = 1;
    pathVis[src] = 1;

    for (auto it : adj[src])
    {
        if (!vis[it])
        {
            if (dfs(it, adj, vis, pathVis))
                return true;
        }
        else if (pathVis[it])
        {
            return true;
        }
    }

    pathVis[src] = 0;
    return false;
}

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    int vis[V] = {0};
    int pathVis[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathVis))
                return true;
        }
    }

    return false;
}
int main()
{
    return 0;
}