#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &nums)
{
    int maxInd = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (maxInd < i)
            return false;
        maxInd = max(maxInd, nums[i] + i);
    }
    return true;
}
int main()
{
    return 0;
}