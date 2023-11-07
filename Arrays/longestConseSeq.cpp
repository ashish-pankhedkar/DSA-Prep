#include <bits/stdc++.h>
using namespace std;
int longestConsecutive_USING_SET(vector<int> &nums)
{
    unordered_set<int> store;
    for (int i = 0; i < nums.size(); i++)
    {
        store.insert(nums[i]);
    }
    int maxi = 0;
    for (auto i : store)
    {   //if the preevious element is not present means that it is the start of seq
        if (store.find(i - 1) == store.end())
        {
            int count = 1;
            int finder = i + 1;
            //count all the further elements present
            while (store.find(finder++) != store.end())
            {
                count++;
            }
            maxi = max(maxi, count);
        }
    }
    return maxi;
}
int main()
{
    return 0;
}