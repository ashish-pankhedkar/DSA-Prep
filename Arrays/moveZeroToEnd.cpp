#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int firstZero = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            firstZero = i;
            break;
        }
    }

    if (firstZero == -1)
        return;

    for (int i = firstZero + 1; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[firstZero] = nums[i];
            nums[i] = 0;
            firstZero++;
        }
    }
}
int main()
{
    return 0;
}