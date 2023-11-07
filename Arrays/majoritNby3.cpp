#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    vector<int> ans;

    int c1 = 0, c2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    int mini = nums.size() / 3 + 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (c1 == 0 && nums[i] != el2)
        {
            c1 = 1;
            el1 = nums[i];
        }
        else if (c2 == 0 && nums[i] != el1)
        {
            c2 = 1;
            el2 = nums[i];
        }
        else if (el1 == nums[i])
        {
            c1++;
        }
        else if (el2 == nums[i])
        {
            c2++;
        }
        else
        {
            c1--;
            c2--;
        }
    }

    c1 = 0;
    c2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)
            c1++;
        if (nums[i] == el2)
            c2++;
    }

    if (c1 >= mini)
    {
        ans.push_back(el1);
    }
    if (c2 >= mini)
    {
        ans.push_back(el2);
    }

    return ans;
}
int main()
{
    return 0;
}