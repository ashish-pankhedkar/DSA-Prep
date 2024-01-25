#include <bits/stdc++.h>
using namespace std;
bool detectCycle(int src, vector<int> adj[], vector<int> &vis)
{
    // Write your code here.

    queue<pair<int, int>> q;
    q.push({src, -1});
    vis[src] = 1;

    while (!q.empty())
    {
        int curr = q.front().first;
        int par = q.front().second;
        q.pop();

        for (auto it : adj[curr])
        {
            if (vis[it] == 0)
            {
                q.push({it, curr});
                vis[it] = 1;
            }
            else if (it != par)
            {
                return true;
            }
            else
            {
                continue;
            }
        }
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
            if (detectCycle(i, adj, vis))
                return true;
        }
    }

    return false;
}
int main()
{
    return 0;
}