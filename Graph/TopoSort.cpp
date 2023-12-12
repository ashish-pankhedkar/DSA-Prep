#include <bits/stdc++.h>
using namespace std;
void dfs(int src, vector<int> adj[], vector<int> &vis, stack<int> &s)
{
    vis[src] = 1;

    for (auto it : adj[src])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, s);
        }
    }
    s.push(src);
}
// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here

    vector<int> vis(V, 0);
    stack<int> s;
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, s);
        }
    }

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}
int main()
{
    return 0;
}