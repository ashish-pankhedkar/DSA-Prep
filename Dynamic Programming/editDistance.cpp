#include <bits/stdc++.h>
using namespace std;

// memoization

int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    else if (j < 0)
        return i + 1;
    else if (dp[i][j] != -1)
        return dp[i][j];
    else if (s1[i] == s2[j])
    {
        return dp[i][j] = helper(i - 1, j - 1, s1, s2, dp);
    }
    else
    {
        int del = 1 + helper(i - 1, j, s1, s2, dp);
        int add = 1 + helper(i, j - 1, s1, s2, dp);
        int rep = 1 + helper(i - 1, j - 1, s1, s2, dp);
        return dp[i][j] = min(rep, min(add, del));
    }
}
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(n - 1, m - 1, word1, word2, dp);
}

// Tabulation
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[n][m];
}

// space optimization
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                curr[j] = prev[j - 1];
            }
            else
            {
                curr[j] = 1 + min(prev[j], min(curr[j - 1], prev[j - 1]));
            }
        }
        prev = curr;
    }
    return curr[m];
}
int main()
{
    return 0;
}