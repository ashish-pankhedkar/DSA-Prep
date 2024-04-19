#include <bits/stdc++.h>
using namespace std;
bool remainderSum(vector<int> &nums, int divisor, int threshold)
{
    int total_sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        total_sum += ceil((double)nums[i] / divisor);
        if (total_sum > threshold)
            return false;
    }
    return true;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int maxi = 0;
    for (auto it : nums)
    {
        maxi = max(maxi, it);
    }

    int low = 1, high = maxi, mini = maxi;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (remainderSum(nums, mid, threshold))
        {

            high = mid - 1;
            mini = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return mini;
}
int main()
{
    return 0;
}