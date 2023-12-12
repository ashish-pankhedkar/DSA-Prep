#include <bits/stdc++.h>
using namespace std;
bool checkbipartite(vector<vector<int>> &graph, int src, vector<int> &color)
{
    queue<int> q;

    q.push(src);
    color[src] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto it : graph[curr])
        {
            if (color[it] == -1)
            {
                q.push(it);
                color[it] = !color[curr];
            }
            else if (color[it] == color[curr])
            {
                return false;
            }
        }
    }

    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int vertices = graph.size();

    vector<int> color(vertices, -1);

    for (int i = 0; i < vertices; i++)
    {
        if (color[i] == -1)
        {
            if (checkbipartite(graph, i, color) == false)
            {
                return false;
            }
        }
    }

    return true;
}
int main()
{
    return 0;
}