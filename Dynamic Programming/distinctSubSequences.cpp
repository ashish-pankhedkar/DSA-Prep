#include <bits/stdc++.h>
using namespace std;
//memoization
int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    else if (i < 0)
        return 0;
    else if (dp[i][j] != -1)
        return dp[i][j];
    else if (s[i] == t[j])
    {
        return dp[i][j] = helper(i - 1, j, s, t, dp) +
                          helper(i - 1, j - 1, s, t, dp);
    }
    return dp[i][j] = helper(i - 1, j, s, t, dp);
}
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(n - 1, m - 1, s, t, dp);
}

//Tabulation
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
int main()
{
    return 0;
}