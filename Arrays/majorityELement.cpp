#include <bits/stdc++.h>
using namespace std;

int majorityElement_VOTING_ALGO(vector<int> &nums)
{
    int element;
    int counter = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (counter == 0)
        {
            element = nums[i];
        }
        if (nums[i] == element)
            counter++;
        else
            counter--;
    }

    counter = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == element)
            counter++;
    }
    return counter > nums.size() / 2 ? element : -1;
}
int majorityElement_MAP(vector<int> &nums)
{
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second > nums.size() / 2)
            return it.first;
    }
    return -1;
}
int main()
{
    return 0;
}