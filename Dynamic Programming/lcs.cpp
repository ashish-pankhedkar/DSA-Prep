#include <bits/stdc++.h>
using namespace std;

// Memization
int helper(string &s1, string &s2, int i1, int i2, vector<vector<int>> &dp)
{
    if (i1 < 0 || i2 < 0)
        return 0;
    else if (dp[i1][i2] != -1)
        return dp[i1][i2];
    else if (s1[i1] == s2[i2])
        return dp[i1][i2] = (1 + helper(s1, s2, i1 - 1, i2 - 1, dp));
    else
    {
        return dp[i1][i2] = max(helper(s1, s2, i1, i2 - 1, dp), helper(s1, s2, i1 - 1, i2, dp));
    }
}
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    helper(text1, text2, n - 1, m - 1, dp);
    return dp[n - 1][m - 1];
}

// tabulation
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = (1 + dp[i - 1][j - 1]);
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

// space optimization
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length();
    int m = text2.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                curr[j] = (1 + prev[j - 1]);
            else
            {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }

    return prev[m];
}
int main()
{
    return 0;
}