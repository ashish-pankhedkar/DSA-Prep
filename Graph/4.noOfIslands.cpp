#include <bits/stdc++.h>
using namespace std;

// This implementation considers diagonal connections as well, Leetcode q doesnt so only 4 neighbours are there.
void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int i, int j)
{
    int maxRow = grid.size();
    int maxCol = grid[0].size();

    queue<pair<int, int>> q;
    q.push({i, j});

    vis[i][j] = 1;

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int delRow = -1; delRow <= 1; delRow++)
        {
            for (int delCol = -1; delCol <= 1; delCol++)
            {
                int nRow = row + delRow;
                int nCol = col + delCol;

                if (nRow >= 0 && nRow < maxRow && nCol >= 0 && nCol < maxCol && !vis[nRow][nCol] && grid[nRow][nCol] == '1')
                {
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                }
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int maxRow = grid.size();
    int maxCol = grid[0].size();

    vector<vector<int>> vis(maxRow, vector<int>(maxCol, 0));
    int count = 0;
    for (int row = 0; row < maxRow; row++)
    {
        for (int col = 0; col < maxCol; col++)
        {
            if (!vis[row][col] && grid[row][col] == '1')
            {
                bfs(grid, vis, row, col);
                count++;
            }
        }
    }

    return count;
}
int main()
{
    return 0;
}