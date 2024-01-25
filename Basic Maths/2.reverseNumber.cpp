#include <bits/stdc++.h>
using namespace std;
int reverse(int x)
{
    long long ans = 0;
    while (x)
    {
        ans = (ans * 10) + (x % 10);
        x /= 10;
    }
    if (ans > INT_MAX || ans < INT_MIN)
        return 0;
    else
        ;
    return (int)ans;
}
int main()
{
    return 0;
}