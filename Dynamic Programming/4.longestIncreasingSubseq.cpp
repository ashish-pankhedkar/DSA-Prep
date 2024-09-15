#include <bits/stdc++.h>
using namespace std;
// Memoization
int helper(int ind, int prevind, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == nums.size())
        return 0;
    if (dp[ind][prevind + 1] != -1)
        return dp[ind][prevind + 1];
    int len1 = 0 + helper(ind + 1, prevind, nums, dp);
    int len2 = 0;
    if (prevind == -1 || nums[ind] > nums[prevind])
    {
        len2 = 1 + helper(ind + 1, ind, nums, dp);
    }
    return dp[ind][prevind + 1] = max(len1, len2);
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return helper(0, -1, nums, dp);
}

// tabiulation
int helper(int ind, int prevind, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == nums.size())
        return 0;
    if (dp[ind][prevind + 1] != -1)
        return dp[ind][prevind + 1];
    int len1 = 0 + helper(ind + 1, prevind, nums, dp);
    int len2 = 0;
    if (prevind == -1 || nums[ind] > nums[prevind])
    {
        len2 = 1 + helper(ind + 1, ind, nums, dp);
    }
    return dp[ind][prevind + 1] = max(len1, len2);
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    // n+1 is declared because we are doing ind+1 line 49. We need to do prevInd +1 do access dp
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prevind = ind - 1; prevind >= -1; prevind--)
        {
            int len1 = dp[ind + 1][prevind + 1]; // this means starting from next index and given prevInd. remember we need to do +1 for prev ind
            int len2 = 0;
            if (prevind == -1 || nums[ind] > nums[prevind])
            {
                len2 = 1 + dp[ind + 1][ind + 1]; // this means starting from next index and current indx as prev index . remember we need to do +1 for prev ind
            }
            dp[ind][prevind + 1] = max(len1, len2);
        }
    }
    return dp[0][0];
}

// Space Optimized

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> next(n + 1, 0), curr(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prevind = ind - 1; prevind >= -1; prevind--)
        {
            int len1 = next[prevind + 1];
            int len2 = 0;
            if (prevind == -1 || nums[ind] > nums[prevind])
            {
                len2 = 1 + next[ind + 1];
            }
            curr[prevind + 1] = max(len1, len2);
        }
        next = curr;
    }
    return curr[0];
}
int main()
{
    return 0;
}