#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &nums)
{
    int ind = -1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = nums.size() - 1; i >= ind; i--)
    {
        if (nums[i] > nums[ind])
        {
            swap(nums[ind], nums[i]);
            break;
        }
    }

    reverse(nums.begin() + ind + 1, nums.end());
    return;
}
int main()
{
    return 0;
}