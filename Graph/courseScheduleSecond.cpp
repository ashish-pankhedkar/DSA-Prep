#include <bits/stdc++.h>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> ans;
    vector<int> adj[numCourses];
    vector<int> indegree(numCourses, 0);

    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
        indegree[it[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for (auto it : adj[curr])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    if (ans.size() != numCourses)
    {
        return {};
    }
    else
        return ans;
}
int main()
{
    return 0;
}