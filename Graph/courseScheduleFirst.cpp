#include <bits/stdc++.h>
using namespace std;
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
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

    int count = 0;
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
                q.push(it);
            }
        }
    }

    return count == numCourses;
}
int main()
{
    return 0;
}