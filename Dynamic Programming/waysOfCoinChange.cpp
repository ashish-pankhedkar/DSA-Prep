#include <bits/stdc++.h>
using namespace std;
// Memoization
int helper(int i, int target, vector<int> &coins, vector<vector<int>> &dp)
{
    if (i == 0)
        return (target % coins[0] == 0);
    else if (target < 0)
        return 0;
    else if (dp[i][target] != -1)
        return dp[i][target];
    else
    {
        int take = helper(i, target - coins[i], coins, dp);
        int nottake = helper(i - 1, target, coins, dp);
        return dp[i][target] = take + nottake;
    }
}
int change(int amount, vector<int> &coins)
{
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    return helper(coins.size() - 1, amount, coins, dp);
}

// tabulationb
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
    for (int i = 0; i <= amount; i++)
    {
        dp[0][i] = (i % coins[0] == 0);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int take = j - coins[i] >= 0 ? dp[i][j - coins[i]] : 0;
            int nottake = dp[i - 1][j];
            dp[i][j] = take + nottake;
        }
    }
    return dp[n - 1][amount];
}

// Space optimization
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
    for (int i = 0; i <= amount; i++)
    {
        prev[i] = (i % coins[0] == 0);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int take = j - coins[i] >= 0 ? curr[j - coins[i]] : 0;
            int nottake = prev[j];
            curr[j] = take + nottake;
        }
        prev = curr;
    }
    return prev[amount];
}
int main()
{
    return 0;
}