#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum_MAP(vector<int> &nums, int target)
{
    map<int, int> mm;
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i <= n - 1; i++)
    {
        int tofind = target - nums[i];
        if (mm.find(tofind) != mm.end())
        {
            ans.push_back(mm[tofind]);
            ans.push_back(i);
            break;
        }
        else
        {
            mm[nums[i]] = i;
        }
    }
    return ans;
}

vector<int> twoSum_SORTING(vector<int> &nums, int target)
{

    vector<int> ans;
    vector<pair<int, int>> help;
    for (int i = 0; i < nums.size(); i++)
    {
        help.push_back({nums[i], i});
    }
    sort(help.begin(), help.end());
    int start = 0;
    int end = help.size() - 1;
    while (start < end)
    {
        if (help[start].first + help[end].first == target)
        {
            ans.push_back(help[start].second);
            ans.push_back(help[end].second);
            return ans;
        }
        else if (help[start].first + help[end].first > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return ans;
}
int main()
{
    return 0;
}