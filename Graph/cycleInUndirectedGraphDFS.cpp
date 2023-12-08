#include <bits/stdc++.h>
using namespace std;
bool detectCycle(int src, int parent, vector<int> adj[], vector<int> &vis)
{
    // Write your code here.
    vis[src] = 1;

    for (auto it : adj[src])
    {
        if (vis[it] == 0)
        {
            if (detectCycle(it, src, adj, vis))
                return true;
        }
        else if (it != parent)
            return true;
    }

    return false;
}

bool isCyclePresent(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, 0);

    for (int i = 1; i < V; i++)
    {
        if (!vis[i])
        {
            if (detectCycle(i, -1, adj, vis))
                return true;
        }
    }

    return false;
}
int main()
{   
    return 0;
}