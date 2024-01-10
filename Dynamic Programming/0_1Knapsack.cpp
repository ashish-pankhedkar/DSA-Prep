#include <bits/stdc++.h>
using namespace std;
int helper(int ind, int wtleft, int wt[], int val[], vector<vector<int>> &dp)
{

    if (wtleft <= 0)
        return 0;
    else if (ind == 0)
        return (wtleft >= wt[0] ? val[0] : 0);
    else if (dp[ind][wtleft] != -1)
        return dp[ind][wtleft];
    else
    {

        int take = wt[ind] <= wtleft ? helper(ind - 1, wtleft - wt[ind], wt, val, dp) + val[ind] : INT_MIN;
        int notTake = helper(ind - 1, wtleft, wt, val, dp);
        return dp[ind][wtleft] = max(take, notTake);
    }
}
// Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return helper(n - 1, W, wt, val, dp);
}
// Tabulation

int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here

    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int i = 0; i <= W; i++)
    {
        if (wt[0] <= i)
        {
            dp[0][i] = val[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {

            int take = (j >= wt[i]) ? dp[i - 1][j - wt[i]] + val[i] : 0;
            int nottake = dp[i - 1][j];
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n - 1][W];
}

// Space optrimization
int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here

    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    for (int i = 0; i <= W; i++)
    {
        if (wt[0] <= i)
        {
            prev[i] = val[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int take = (j >= wt[i]) ? prev[j - wt[i]] + val[i] : 0;
            int nottake = prev[j];
            curr[j] = max(take, nottake);
        }
        prev = curr;
    }
    return prev[W];
}


// one array 
int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here

    vector<int>  curr(W + 1, 0);

    for (int i = 0; i <= W; i++)
    {
        if (wt[0] <= i)
        {
            curr[i] = val[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = W; j >= 0; j++)
        {
            int take = (j >= wt[i]) ? curr[j - wt[i]] + val[i] : 0;
            int nottake = curr[j];
            curr[j] = max(take, nottake);
        }
      
    }
    return curr[W];
}
int main()
{
    return 0;
}