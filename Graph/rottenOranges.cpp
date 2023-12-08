#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    // get sizes
    int maxrow = grid.size();
    int maxcol = grid[0].size();
    // del
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    //{{row,col},time}
    queue<pair<pair<int, int>, int>> q;
    // intitialize vis and push rotten oranges in queue
    for (int i = 0; i < maxrow; i++)
    {
        for (int j = 0; j < maxcol; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
            }
        }
    }

    int mintime = 0;

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        mintime = max(mintime, time);
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = delRow[i] + row;
            int ncol = delCol[i] + col;

            if (nrow >= 0 && nrow < maxrow && ncol >= 0 && ncol < maxcol && grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, time + 1});
            }
        }
    }

    for (int i = 0; i < maxrow; i++)
    {
        for (int j = 0; j < maxcol; j++)
        {
            if (grid[i][j] == 1)
            {
                return -1;
            }
        }
    }

    return mintime;
}
int main()
{
    return 0;
}