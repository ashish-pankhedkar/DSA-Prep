#include <bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here

    queue<int> q;
    int vis[V] = {0};
    vector<int> ans;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for (int it : adj[temp])
        {
            if (vis[it] != 1)
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ans;
}
int main()
{
    return 0;
}