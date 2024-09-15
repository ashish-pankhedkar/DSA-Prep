#include <bits/stdc++.h>
using namespace std;
// Mmemoization
bool helper(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    else if (target < 0)
        return false;
    else if (ind == 0)
        return arr[0] == target;
    else if (dp[ind][target] != -1)
        return dp[ind][target];
    else
    {
        bool take = helper(ind - 1, target - arr[ind], arr, dp);
        bool nottake = helper(ind - 1, target, arr, dp);
        return dp[ind][target] = take || nottake;
    }
}
bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return helper(n - 1, sum, arr, dp);
}

// Tabulation
bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    // first row
    if (arr[0] < sum + 1)
        dp[0][arr[0]] = true;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j] || (j - arr[i] >= 0 ? dp[i - 1][j - arr[i]] : 0);
        }
    }

    return dp[n - 1][sum];
}

// space optimization
bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    int n = arr.size();
    vector<bool> prev(sum + 1, false), curr(sum + 1, true);

    // first row
    if (arr[0] < sum + 1)
        prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        curr[0] = true;
        for (int j = 1; j <= sum; j++)
        {
            curr[j] = prev[j] || (j - arr[i] >= 0 ? prev[j - arr[i]] : false);
        }
        prev = curr;
    }

    return curr[sum];
}
int main()
{
    return 0;
}