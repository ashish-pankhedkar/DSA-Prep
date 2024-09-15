#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int ones = 0;
    int two = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ones = ((ones ^ nums[i]) & (~two));
        two = ((two ^ nums[i]) & (~ones));
    }
    return ones;
}
bool checkIBit(int n, int i)
{
    return (n & (1 << i));
}
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int b = 0; b < 32; b++)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (checkIBit(nums[i], b))
                cnt++;
        }
        if (cnt % 3 == 1)
        {
            ans = ans | (1 << b);
        }
    }
    return ans;
}
int main()
{
    return 0;
}