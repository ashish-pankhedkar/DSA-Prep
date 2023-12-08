#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis)
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

        if (nrow >= 0 && nrow < maxrow && ncol >= 0 && ncol < maxcol && !vis[nrow][ncol] && grid[nrow][ncol] == 'O')
        {
            dfs(nrow, ncol, grid, vis);
        }
    }
}
void solve(vector<vector<char>> &board)
{

    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O' && !vis[i][0])
        {
            dfs(i, 0, board, vis);
        }

        if (board[i][m - 1] == 'O' && !vis[i][m - 1])
        {
            dfs(i, m - 1, board, vis);
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (board[0][j] == 'O' && !vis[0][j])
        {
            dfs(0, j, board, vis);
        }
        if (board[n - 1][j] == 'O' && !vis[n - 1][j])
        {
            dfs(n - 1, j, board, vis);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vis[i][j] << " ";
            if (board[i][j] == 'O' && vis[i][j] == 0)
            {
                board[i][j] = 'X';
            }
        }
        cout << endl;
    }
}
int main()
{
    return 0;
}