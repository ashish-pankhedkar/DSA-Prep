#include <bits/stdc++.h>
using namespace std;
nt singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans ^= nums[i];
    }
    return ans;
}
int main()
{
    return 0;
}