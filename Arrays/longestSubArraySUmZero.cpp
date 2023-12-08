#include <bits/stdc++.h>
using namespace std;
int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    // Write your code here.
    int maxi = 0;
    unordered_map<long long, int> mp;

    long long sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxi = max(maxi, i + 1);
        }
        else if (mp.find(sum) != mp.end())
        {
            int arrLen = i - mp[sum];
            maxi = max(maxi, arrLen);
        }
        else
        {
            mp[sum] = i;
        }
    }

    return maxi;
}
int main()
{
    return 0;
}