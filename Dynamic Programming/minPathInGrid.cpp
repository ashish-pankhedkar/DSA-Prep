#include <bits/stdc++.h>
using namespace std;
// Memoization

int helper(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &grid)
{
    if (row == 0 && col == 0)
        return grid[0][0];
    else if (row < 0 || col < 0)
        return INT_MAX;
    else if (dp[row][col] != -1)
        return dp[row][col];
    else
    {
        return dp[row][col] = min(helper(row - 1, col, dp, grid), helper(row, col - 1, dp, grid)) + grid[row][col];
    }
}
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(n - 1, m - 1, dp, grid);
}

// Tabulation
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[0][0];
            }

            else if (i == 0 || j == 0)
            {
                dp[i][j] = (i == 0 ? dp[i][j - 1] : dp[i - 1][j]) + grid[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
    }
    return dp[n - 1][m - 1];
}

int main()
{
    return 0;
}