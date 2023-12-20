#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, S});

    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    while (!q.empty())
    {
        int currdist = q.top().first;
        int currnode = q.top().second;
        q.pop();

        dist[currnode] = min(dist[currnode], currdist);

        for (auto it : adj[currnode])
        {
            int adjnode = it[0];
            int adjwt = it[1];

            if (dist[adjnode] > (currdist + adjwt))
            {
                q.push({currdist + adjwt, adjnode});
            }
        }
    }

    return dist;
}
int main()
{
    return 0;
}