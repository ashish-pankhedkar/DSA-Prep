#include <bits/stdc++.h>
using namespace std;
// memoization
int helper(int i, vector<int> &dp, vector<int> &heights)
{

    if (i <= 0)
        return 0;
    else if (i == 1)
        return abs(heights[1] - heights[0]);
    else if (dp[i] != -1)
        return dp[i];
    else
    {

        int oneStep = helper(i - 1, dp, heights) + abs(heights[i - 1] - heights[i]);
        int twoStep = helper(i - 2, dp, heights) + abs(heights[i - 2] - heights[i]);
        return dp[i] = min(oneStep, twoStep);
    }
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n, -1);
    return helper(n - 1, dp, heights);
}

// tabulation
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n, -1);
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);

    for (int i = 2; i < n; i++)
    {
        int oneJump = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int twoJump = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(oneJump, twoJump);
    }
    return dp[n - 1];
}

// SPace optimization

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.

    int pprev = 0;
    int prev = abs(heights[1] - heights[0]);
    int curr;

    for (int i = 2; i < n; i++)
    {
        int oneJump = prev + abs(heights[i] - heights[i - 1]);
        int twoJump = pprev + abs(heights[i] - heights[i - 2]);
        curr = min(oneJump, twoJump);
        pprev = prev;
        prev = curr;
    }
    return curr;
}
int main()
{
    return 0;
}