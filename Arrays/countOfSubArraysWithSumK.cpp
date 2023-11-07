#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> prefixSum;

    int count = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == k)
            count++;
        if (prefixSum.find(sum - k) != prefixSum.end())
        {
            count += prefixSum[sum - k];
        }

        if (prefixSum.find(sum) != prefixSum.end())
        {
            prefixSum[sum]++;
        }
        else
        {
            prefixSum[sum] = 1;
        }
    }
    return count;
}
int main()
{
    return 0;
}