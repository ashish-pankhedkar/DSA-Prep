#include <bits/stdc++.h>
using namespace std;
vector<int> singleNumber(vector<int> &nums)
{
    long long allXOR = 0;
    for (int i : nums)
        allXOR ^= i;

    long long diffBit = (allXOR & (allXOR - 1)) ^ allXOR;
    int num1 = 0, num2 = 0;
    for (int i : nums)
    {
        if (diffBit & i)
        {
            num1 ^= i;
        }
        else
        {
            num2 ^= i;
        }
    }
    return {num1, num2};
}
int main()
{
    return 0;
}