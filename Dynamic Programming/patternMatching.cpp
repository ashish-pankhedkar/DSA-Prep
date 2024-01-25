#include <bits/stdc++.h>
using namespace std;
bool helper(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    else if (j < 0 && i >= 0)
        return false;
    else if (i < 0 && j >= 0)
    {
        for (int k = 0; k <= j; k++)
        {
            if (p[k] != '*')
                return false;
        }
        return true;
    }
    else if (dp[i][j] != -1)
        return dp[i][j];
    else if (s[i] == p[j] || p[j] == '?')
    {
        return dp[i][j] = helper(i - 1, j - 1, s, p, dp);
    }
    else if (p[j] == '*')
    {
        return dp[i][j] =
                   helper(i - 1, j, s, p, dp) || helper(i, j - 1, s, p, dp);
    }
    else
    {
        return dp[i][j] = false;
    }
}
bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(n - 1, m - 1, s, p, dp);
}

// tabulation
bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));

    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
        dp[i][0] = false;

    for (int i = 1; i <= m; i++)
    {
        int flag = true;
        for (int j = 0; j < i; j++)
        {
            if (p[j] != '*')
            {
                flag = false;
                break;
            }
        }
        flag ? dp[0][i] = true : dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}

// Space optmizattion

bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<int> curr(m + 1, false);
    vector<int> prev(m + 1, false);

    prev[0] = true;

    for (int i = 1; i <= m; i++)
    {
        int flag = true;
        for (int j = 0; j < i; j++)
        {
            if (p[j] != '*')
            {
                flag = false;
                break;
            }
        }
        flag ? prev[i] = true : prev[i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        curr[0] = false;
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                curr[j] = prev[j - 1];
            }
            else if (p[j - 1] == '*')
            {
                curr[j] = prev[j] || curr[j - 1];
            }
            else
            {
                curr[j] = false;
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