#include <bits/stdc++.h>
using namespace std;
int divide(int dividend, int divisor)
{
    bool sign = true;
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        sign = false;
    long dd = abs(dividend);
    long d = abs(divisor);
    long ans = 0;
    while (dd >= d)
    {
        int q = 0;
        while (dd >= (d << (q + 1)))
            q++;

        ans += (1 << q);
        dd -= (d << q);
    }

    if (ans == (1 << 31) && sign)
        return INT_MAX;
    if (ans == (1 << 31) && !sign)
        return INT_MIN;

    return sign ? ans : (-1 * ans);
}
int main()
{
    return 0;
}