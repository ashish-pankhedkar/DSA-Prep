#include <bits/stdc++.h>
using namespace std;
vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    unordered_map<int, int> mp;
    for (auto it : arr1)
    {
        mp[it]++;
    }

    vector<int> ans;
    int count = 0;

    for (auto it : arr2)
    {
        for (int i = 0; i < mp[it]; i++)
        {
            ans.push_back(it);
            count++;
        }
        mp.erase(it);
    }

    for (auto it : mp)
    {
        for (int i = 0; i < it.second; i++)
        {
            ans.push_back(it.first);
        }
    }

    int m = arr2.size();
    sort(ans.begin() + count, ans.end());
    return ans;
}
int main()
{
    return 0;
}