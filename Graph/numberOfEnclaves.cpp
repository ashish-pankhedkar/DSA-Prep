#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis)
{
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    int maxrow = grid.size();
    int maxcol = grid[0].size();

    vis[row][col] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < maxrow && ncol >= 0 && ncol < maxcol && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, grid, vis);
        }
    }
}
int numEnclaves(vector<vector<int>> &board)
{

    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 1 && !vis[i][0])
        {
            dfs(i, 0, board, vis);
        }

        if (board[i][m - 1] == 1 && !vis[i][m - 1])
        {
            dfs(i, m - 1, board, vis);
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (board[0][j] == 1 && !vis[0][j])
        {
            dfs(0, j, board, vis);
        }

        if (board[n - 1][j] == 1 && !vis[n - 1][j])
        {
            dfs(n - 1, j, board, vis);
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (board[i][j] == 1 && vis[i][j] == 0)
            {
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