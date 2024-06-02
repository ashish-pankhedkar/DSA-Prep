#include <bits/stdc++.h>
using namespace std;

int longestOnes_OPTMIZED(vector<int> &nums, int k)
{
    int n = nums.size();
    int zeros = 0;
    int l = 0, r = 0, maxi = 0;
    while (r < n)
    {
        if (nums[r] == 0)
        {
            zeros++;
        }
        if (zeros > k)
        {
            if (nums[l] == 0)
                zeros--;
            l++;
        }

        if (zeros <= k)
            maxi = max(maxi, r - l + 1);
        r++;
    }
    return maxi;
}

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> mp;
    int n = s.size();
    int l = 0, r = 0, maxi = 0;
    while (r < n)
    {
        if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l)
        {
            l = mp[s[r]] + 1;
        }

        mp[s[r]] = r;

        maxi = max(maxi, r - l + 1);
        r++;
    }
    return maxi;
}
int main()
{
    return 0;
}