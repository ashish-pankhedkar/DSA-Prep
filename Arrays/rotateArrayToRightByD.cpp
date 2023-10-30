#include <bits/stdc++.h>
using namespace std;
void rotateRight(vector<int> &nums, int k)
{
    k %= nums.size();
    int temp = nums.size() - k;
    reverse(nums.begin(), nums.begin() + temp);
    reverse(nums.begin() + temp, nums.end());
    reverse(nums.begin(), nums.end());
}

void rotateLeft(vector<int> &nums, int k)
{
    k %= nums.size();
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());
}
int main()
{
    return 0;
}