#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION

int helper(int i, int j, int n, vector<vector<int>> &dp, vector<vector<int>> &matrix)
{
    if (j < 0 || j >= n)
        return INT_MAX;
    else if (i == 0)
        return matrix[i][j];
    else if (dp[i][j] != INT_MAX)
        return dp[i][j];
    else
    {
        int right = helper(i - 1, j + 1, n, dp, matrix);
        int up = helper(i - 1, j, n, dp, matrix);
        int left = helper(i - 1, j - 1, n, dp, matrix);
        return dp[i][j] = min(right, min(up, left)) + matrix[i][j];
    }
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        mini = min(mini, helper(n - 1, i, n, dp, matrix));
    }
    return mini;
}

// tabulation

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int mini = INT_MAX;
    // all the endpoints in last row

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++)
        {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int up = dp[i - 1][j], right = INT_MAX, left = INT_MAX;
                if (j - 1 >= 0)
                    left = dp[i - 1][j - 1];
                if (j + 1 < n)
                    right = dp[i - 1][j + 1];

                dp[i][j] = min(right, min(left, up)) + matrix[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, dp[n - 1][i]);
        }
    
    return mini;
}

// space optimization

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int mini = INT_MAX;


        vector<int> prev(n), curr(n);

        for (int i = 0; i < n; i++)
        {
            prev[i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int up = prev[j], right = INT_MAX, left = INT_MAX;
                if (j - 1 >= 0)
                    left = prev[j - 1];
                if (j + 1 < n)
                    right = prev[j + 1];

                curr[j] = min(right, min(left, up)) + matrix[i][j];
            }
            prev = curr;
        }
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, prev[i]);
        }
    

    return mini;
}
int main()
{
    return 0;
}