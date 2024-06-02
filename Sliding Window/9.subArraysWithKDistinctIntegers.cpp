#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> &nums, int k)
{
    if (k == 0)
        return 0;
    int n = nums.size();
    unordered_map<int, int> mp;
    int maxi = 0;
    int l = 0, r = 0, c = 0;
    while (r < n)
    {
        mp[nums[r]]++;
        while (mp.size() > k)
        {
            mp[nums[l]]--;
            if (mp[nums[l]] == 0)
                mp.erase(nums[l]);
            l++;
        }
        c += (r - l + 1);
        r++;
    }
    return c;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return helper(nums, k) - helper(nums, k - 1);
}
int main()
{
    return 0;
}