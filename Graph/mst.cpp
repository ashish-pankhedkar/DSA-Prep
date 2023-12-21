#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    int sum = 0;
    vector<int> vis(V, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, 0});

    while (!q.empty())
    {
        int wt = q.top().first;
        int currnode = q.top().second;

        q.pop();

        if (!vis[currnode])
        {
            vis[currnode] = 1;
            sum += wt;

            for (auto it : adj[currnode])
            {
                int adjnode = it[0];
                int adjwt = it[1];
                if (!vis[adjnode])
                {
                    q.push({adjwt, adjnode});
                }
            }
        }
    }
    return sum;
}
int main()
{
    return 0;
}