#include <bits/stdc++.h>
using namespace std;
// /MEMOIZATION
int helper(int i, int act, vector<vector<int>> &dp, vector<vector<int>> &points)
{
    if (i < 0)
        return 0;
    else if (dp[i][act] != -1)
        return dp[i][act];
    else
    {
        if (act == 0)
        {
            // we can do act 1 and act 2
            int act1 = helper(i - 1, 1, dp, points);
            int act2 = helper(i - 1, 2, dp, points);
            return dp[i][0] = max(act1, act2) + points[i][0];
        }
        else if (act == 1)
        {
            int act0 = helper(i - 1, 0, dp, points);
            int act2 = helper(i - 1, 2, dp, points);
            return dp[i][1] = max(act0, act2) + points[i][1];
        }
        else
        {
            int act1 = helper(i - 1, 1, dp, points);
            int act0 = helper(i - 1, 0, dp, points);
            return dp[i][2] = max(act1, act0) + points[i][2];
        }
    }
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(3, -1));
    int act0 = helper(n - 1, 0, dp, points);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = -1;
        }
    }
    int act1 = helper(n - 1, 1, dp, points);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = -1;
        }
    }
    int act2 = helper(n - 1, 2, dp, points);

    return max(act0, max(act1, act2));
}

// Tabulation

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(3, -1));
    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (k != j)
                {
                    dp[i][j] = max(dp[i - 1][k] + points[i][j], dp[i][j]);
                }
            }
        }
    }
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        maxi = max(maxi, dp[n - 1][i]);
    }
    return maxi;
}

// Space optimization

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here

    vector<int> curr(3, -1), prev(3, -1);
    prev[0] = points[0][0];
    prev[1] = points[0][1];
    prev[2] = points[0][2];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (k != j)
                {
                    curr[j] = max(prev[k] + points[i][j], curr[j]);
                }
            }
        }
        prev = curr;
    }

    return max(curr[0], max(curr[1], curr[2]));
}
int main()
{
    return 0;
}