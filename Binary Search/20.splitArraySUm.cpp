#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> &nums, int sum)
{
    int subs = 1;
    int prevSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (prevSum + nums[i] <= sum)
        {
            prevSum += nums[i];
        }
        else
        {
            subs++;
            prevSum = nums[i];
        }
    }
    return subs;
}
int splitArray(vector<int> &nums, int k)
{
    int high = 0, low = 0;
    for (auto it : nums)
    {
        high += it;
        low = max(low, it);
    }

    int ans = 0;
    while (low <= high)
    {
        int mid = (high - low) / 2 + low;

        if (helper(nums, mid) > k)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    return 0;
}