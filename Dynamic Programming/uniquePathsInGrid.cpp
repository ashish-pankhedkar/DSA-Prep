#include <bits/stdc++.h>
using namespace std;
// Memoization
int helper(int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
        return 1;
    else if (row < 0 || col < 0)
        return 0;

    else if (dp[row][col] != -1)
        return dp[row][col];
    else
    {
        return dp[row][col] = helper(row - 1, col, dp) + helper(row, col - 1, dp);
    }
}

int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(m - 1, n - 1, dp);
}

// TABULATION
int uniquePaths(int m, int n)
{

    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }

            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}
int main()
{
    return 0;
}