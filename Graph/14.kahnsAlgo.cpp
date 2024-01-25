#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> indegree(V);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
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
            indegree[it]--;
            if (indegree[it] == 0)
            {
                ans.push_back(it);
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