#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int num)
{
    if (num < 0)
        return false;
    else
    {
        long long newNum = 0;
        int original = num;
        while (num)
        {
            newNum = newNum * 10 + (num % 10);
            num /= 10;
        }
        if (newNum > INT_MAX)
            return false;
        else
        {
            return newNum == (int)original;
        }
    }
}
int main()
{
    return 0;
}