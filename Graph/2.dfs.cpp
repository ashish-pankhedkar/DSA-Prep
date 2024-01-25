#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans)
{
    vis[node] = 1;
    ans.push_back(node);

    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, adj, vis, ans);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V, 0);
    vector<int> ans;

    dfs(0, adj, vis, ans);
    return ans;
}
int main()
{
    return 0;
}