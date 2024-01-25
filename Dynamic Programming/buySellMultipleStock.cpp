#include <bits/stdc++.h>
using namespace std;
// memoization
int helper(int ind, int buy, vector<vector<int>> &dp, vector<int> &prices)
{
    if (ind == prices.size())
        return 0;

    else if (dp[ind][buy] != -1)
        return dp[ind][buy];
    else
    {
        if (!buy)
        {
            return dp[ind][buy] = max(helper(ind + 1, 1, dp, prices) - prices[ind], helper(ind + 1, 0, dp, prices));
        }
        else
        {
            return dp[ind][buy] = max(helper(ind + 1, 0, dp, prices) + prices[ind], helper(ind + 1, 1, dp, prices));
        }
    }
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return helper(0, 0, dp, prices);
}

// Tabulation
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {

        dp[i][0] = max(dp[i + 1][1] - prices[i], dp[i + 1][0]);
        dp[i][1] = max(dp[i + 1][0] + prices[i], dp[i + 1][1]);
    }

    return dp[0][0]; // retrurn dp[0th ind][buy] since you cant sell on first day
}

// space optimizatiob
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    pair<int, int> prev, curr;
    prev = {0, 0};

    for (int i = n - 1; i >= 0; i--)
    {

        curr.first = max(prev.second - prices[i], prev.first);
        curr.second = max(prev.first + prices[i], prev.second);
        prev = curr;
    }

    return curr.first;
}

int main()
{
    return 0;
}