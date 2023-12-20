#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<pair<int, int>> adj[])
{

    // code here
    vector<int> indegree(V);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it.first]++;
        }
    }

    vector<int> ans;
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            ans.push_back(i);
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto it : adj[curr])
        {
            indegree[it.first]--;
            if (indegree[it.first] == 0)
            {
                ans.push_back(it.first);
                q.push(it.first);
            }
        }
    }

    return ans;
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // code here
    vector<pair<int, int>> adj[N];

    for (int i = 0; i < M; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    vector<int> ans = topoSort(N, adj);

    vector<int> dist(N, -1);

    dist[0] = 0;

    for (int i = 0; i < N; i++)
    {
        int currNode = ans[i];
        int currDist = dist[currNode];
        if (currDist != -1)
        {
            for (auto it : adj[currNode])
            {
                if (dist[it.first] == -1)
                {
                    dist[it.first] = currDist + it.second;
                }
                else
                {
                    dist[it.first] = min(dist[it.first], currDist + it.second);
                }
            }
        }
    }

    return dist;
}
int main()
{
    return 0;
}