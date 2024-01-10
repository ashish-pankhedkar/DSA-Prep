#include <bits/stdc++.h>
using namespace std;
// memoization

int helper(int cut, int length, int price[], vector<vector<int>> &dp)
{
    if (cut == 1)
        return (length * price[0]);
    else if (dp[cut][length] != -1)
        return dp[cut][length];
    else
    {
        int nocut = helper(cut - 1, length, price, dp);
        int ifcut = (length >=cut ? (helper(cut, length - cut, price, dp) + price[cut - 1]) : 0);
        return dp[cut][length] = max(ifcut, nocut);
    }
}
int cutRod(int price[], int n)
{
    // code here
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return helper(n, n, price, dp);
}
// tabulation
int cutRod(int price[], int n)
{
    // code here
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int cutLength = 1; cutLength <= n; cutLength++)
    {
        dp[1][cutLength] = cutLength * price[0];
    }
    for (int cutLength = 2; cutLength <= n; cutLength++)
    {
        for (int rodLength = 1; rodLength <= n; rodLength++)
        {
            int nocut = dp[cutLength - 1][rodLength];
            int cut = rodLength >= cutLength ? (dp[cutLength][rodLength - cutLength] + price[cutLength - 1]) : 0;
            dp[cutLength][rodLength] = max(cut, nocut);
        }
    }
    return dp[n][n];
}
// space optimization
int cutRod(int price[], int n)
{
    // code here
 vector<int> prev(n + 1, 0) ;
    for (int cutLength = 1; cutLength <= n; cutLength++)
    {
        prev[cutLength] = cutLength * price[0];
    }
    for (int cutLength = 2; cutLength <= n; cutLength++)
    {
        for (int rodLength = n; rodLength >=0; rodLength--)
        {
            int nocut = prev[rodLength];
            int cut = rodLength >= cutLength ? (prev[rodLength - cutLength] + price[cutLength - 1]) : 0;
            prev[rodLength] = max(cut, nocut);
        }
    }
    return prev[n];
}
int main()
{
    return 0;
}