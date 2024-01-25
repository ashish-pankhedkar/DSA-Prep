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
string findOrder(string dic[], int N, int K)
{
    // code here
    vector<int> adj[K];

    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dic[i];
        string s2 = dic[i + 1];
        int len = min(s1.size(), s2.size());
        for (int p = 0; p < len; p++)
        {
            if (s1[p] != s2[p])
            {
                adj[s1[p] - 'a'].push_back(s2[p] - 'a');
                break;
            }
        }
    }

    vector<int> ans = topoSort(K, adj);

    string fin = "";
    for (auto it : ans)
    {
        fin += (char)(it + 'a');
    }
    return fin;
}
int main()
{
    return 0;
}