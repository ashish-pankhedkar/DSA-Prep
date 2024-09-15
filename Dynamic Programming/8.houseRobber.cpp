#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
int helper(int n, vector<int> &dp, vector<int> &nums)
{
    if (n < 0)
        return 0;
    else if (dp[n] != -1)
        return dp[n];
    else
    {
        int rob = nums[n] + helper(n - 2, dp, nums);
        int dontrob = helper(n - 1, dp, nums);

        return dp[n] = max(rob, dontrob);
    }
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return helper(n - 1, dp, nums);
}

// TABULATION

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i] = nums[0];
        }
        else if (i == 1)
        {
            dp[i] = max(nums[1], nums[0]);
        }
        else
        {
            int rob = nums[i] + dp[i - 2];
            int dontrob = dp[i - 1];

            dp[i] = max(rob, dontrob);
        }
    }

    return dp[n - 1];
}

// Spacer Optimization

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);

    int prev = 0, curr = 0, pprev = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            curr = nums[0];
        }
        else if (i == 1)
        {
            curr = max(nums[1], nums[0]);
        }
        else
        {
            int rob = nums[i] + pprev;
            int dontrob = prev;

            curr = max(rob, dontrob);
        }
        pprev = prev;
        prev = curr;
    }

    return curr;
}
int main()
{
    return 0;
}