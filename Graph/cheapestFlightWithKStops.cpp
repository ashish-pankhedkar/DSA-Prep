#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<int> cost(n, INT_MAX);
    queue<pair<int, pair<int, int>>> q;
    vector<pair<int, int>> adj[n];
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    cost[src] = 0;
    q.push({0, {src, 0}});

    while (!q.empty())
    {
        int currstops = q.front().first;
        int currnode = q.front().second.first;
        int currcost = q.front().second.second;
        q.pop();

        if (currstops > k)
            continue;

        for (auto it : adj[currnode])
        {
            int adjnode = it.first;
            int extracost = it.second;

            int newcost = currcost + extracost;
            int newstops = currstops + 1;
            if (newcost < cost[adjnode] && currstops <= k)
            {
                cost[adjnode] = newcost;
                q.push({newstops, {adjnode, newcost}});
            }
        }
    }
    return cost[dst] == INT_MAX ? -1 : cost[dst];
}
int main()
{
    return 0;
}