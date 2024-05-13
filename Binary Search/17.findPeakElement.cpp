#include <bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1 || (nums[0] > nums[1]))
        return 0;
    if (nums[n - 2] < nums[n - 1])
        return n - 1;

    int l = 1;
    int h = n - 2;

    while (l < h)
    {
        int mid = (h - l) / 2 + l;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        else if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    return h;
}
int main()
{
    return 0;
}