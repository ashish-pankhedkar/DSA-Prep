#include <bits/stdc++.h>
using namespace std;
int missingNumber_SUM(vector<int> &nums)
{
    int n = nums.size();
    int total = n * (n + 1) / 2;

    for (int i = 0; i < n; i++)
    {
        total -= nums[i];
    }
    return total;
}
int missingNumber_XOR(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans ^= nums[i];
        ans ^= i;
    }
    return ans ^ nums.size();
}
int main()
{
    return 0;
}