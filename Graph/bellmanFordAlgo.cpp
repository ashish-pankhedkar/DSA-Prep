#include <bits/stdc++.h>
using namespace std;


vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    // Code here
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    //here we are doing v iterations because if the last updation is at v-1 iteration it wont update in vth interations and return
    for (int i = 0; i < V; i++)
    {
        bool change = false;

        for (auto it : edges)
        {
            if (dist[it[0]] != 1e8 && dist[it[0]] + it[2] < dist[it[1]])
            {
                dist[it[1]] = dist[it[0]] + it[2];
                change = true;
            }
        }
        if (!change)
            return dist;
    }
    //if it is not returned from the loop it means it got updated for V times i,e it has a negative cycle and hence return -1

    return {-1};
}
int main()
{
    return 0;
}