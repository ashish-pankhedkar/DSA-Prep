#include <bits/stdc++.h>
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.

    map<int, int> mp;

    int count = 0;
    int xr = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xr ^= arr[i];
        if (xr == x)
            count++;
        if (mp.find(xr ^ x) != mp.end())
        {
            count += mp[xr ^ x];
        }
        mp[xr]++;
    }

    return count;
}
int main()
{
    return 0;
}