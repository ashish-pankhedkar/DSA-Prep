#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums)
{
    int maxi = INT_MIN;
    int n = nums.size();
    int pre = 1, suf = 1;
    for (int i = 0; i < n; i++)
    {
        if (suf == 0)
            suf = 1;
        if (pre == 0)
            pre = 1;
        pre *= nums[i];
        suf *= nums[n - 1 - i];
        maxi = max(maxi, max(pre, suf));
    }

    return maxi;
}
int main()
{
    return 0;
}