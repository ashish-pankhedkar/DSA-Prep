#include <bits/stdc++.h>
using namespace std;
// tabulation
int longestCommonSubstr(string S1, string S2, int n, int m)
{
    // your code here
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }

    return ans;
}

// space optimization
int longestCommonSubstr(string S1, string S2, int n, int m)
{
    // your code here
    int ans = 0;

    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                curr[j] = prev[j - 1] + 1;
                ans = max(ans, curr[j]);
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }

    return ans;
}
int main()
{
    return 0;
}