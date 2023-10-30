#include <bits/stdc++.h>
using namespace std;
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void sortColors(vector<int> &nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;
    while (mid < nums.size() && mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main()
{
    return 0;
}