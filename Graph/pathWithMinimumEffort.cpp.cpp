// https://leetcode.com/problems/path-with-minimum-effort/

#include <bits/stdc++.h>
using namespace std;
int minimumEffortPath(vector<vector<int>> &grid)
{
    // sizes
    int n = grid.size();
    int m = grid[0].size();
    // init del, effort, pq
    vector<pair<int, int>> del = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    //change effort for src and push into q
    effort[0][0] = 0;
    q.push({0, {0, 0}});

    while (!q.empty())
    {
        int curreffort = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newx = x + del[i].first;
            int newy = y + del[i].second;

            if (newx >= 0 && newx < n && newy >= 0 && newy < m) //i.e the cell is valid
            {
                int newEffort = max(curreffort, abs(grid[newx][newy] - grid[x][y])); //new effort will be max of previous effort and 
                //difference between curr and adj cell i.e extra effort

                if (newEffort < effort[newx][newy])
                {
                    effort[newx][newy] = newEffort;
                    q.push({newEffort, {newx, newy}});
                }
            }
        }
    }
    return effort[n - 1][m - 1];
}
int main()
{
    return 0;
}