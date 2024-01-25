#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int row0, int col0)
{
    vis[row][col] = 1;
    vec.push_back({row - row0, col - col0});

    int maxrow = grid.size();
    int maxcol = grid[0].size();

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < maxrow && ncol >= 0 && ncol < maxcol && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, vis, grid, vec, row0, col0);
        }
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    // code here
    int maxrow = grid.size();
    int maxcol = grid[0].size();
    set<vector<pair<int, int>>> s;
    vector<vector<int>> vis(maxrow, vector<int>(maxcol, 0));
    for (int i = 0; i < maxrow; i++)
    {
        for (int j = 0; j < maxcol; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> vec;
                dfs(i, j, vis, grid, vec, i, j);
                s.insert(vec);
            }
        }
    }

    return s.size();
}
int main()
{
    return 0;
}