#include <bits/stdc++.h>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    // del co ordinates ie possible neigbours
    if (grid[0][0] == 1)
        return -1;
    int n = grid.size();
    vector<pair<int, int>> del = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    dist[0][0] = 1;
    queue<pair<int, pair<int, int>>> q;
    q.push({1, {0, 0}});

    while (!q.empty())
    {
        int currdist = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (x == n - 1 && y == n - 1)
            return dist[x][y];

        for (int i = 0; i < 8; i++)
        {
            int newx = x + del[i].first;
            int newy = y + del[i].second;

            if (newx >= 0 && newx < n && newy >= 0 && newy < n && grid[newx][newy] == 0 && dist[newx][newy] > currdist + 1)
            {

                dist[newx][newy] = currdist + 1;
                q.push({dist[newx][newy], {newx, newy}});
            }
        }
    }

    return -1;
}
int main()
{
    return 0;
}