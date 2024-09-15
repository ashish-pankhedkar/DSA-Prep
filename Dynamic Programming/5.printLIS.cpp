#include <bits/stdc++.h>
using namespace std;
vector<int> lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int maxi = 0;
    vector<int> dp(n, 1);
    vector<int> hash(n);
    int lastind = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if ((nums[prev] < nums[i]) && (dp[i] < 1 + dp[prev]))
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (maxi < dp[i])
        {
            maxi = dp[i];
            lastind = i;
        }
    }

    vector<int> ans;
    ans.push_back(nums[lastind]);

    while (hash[lastind] != lastind)
    {
        lastind = hash[lastind];
        ans.push_back(nums[lastind]);
    }
     reverse(ans.begin(), ans.end());
     return ans;
}
int main()
{
    return 0;
}