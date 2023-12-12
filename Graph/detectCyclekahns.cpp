#include <bits/stdc++.h>
using namespace std;
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> indegree(V);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    int count = 0;
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
        count++;

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

    return count != V;
}
int main()
{
    return 0;
}