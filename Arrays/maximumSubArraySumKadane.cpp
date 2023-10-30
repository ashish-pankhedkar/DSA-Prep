#include <bits/stdc++.h>
using namespace std;
int maxSubArray_KADANE(vector<int> &nums)
{
    int sum = 0;
    int ansStart,ansEnd;
    int maxi = INT_MIN;
    int start;
    for (int i = 0; i < nums.size(); i++)
    {   if(sum == 0) {
        start = i;
    }
        sum += nums[i];
        if(sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}
int main()
{
    return 0;
}