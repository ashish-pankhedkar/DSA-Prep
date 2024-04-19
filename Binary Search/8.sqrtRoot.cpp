#include <bits/stdc++.h>
using namespace std;
int floorSqrt(int n)
{
#define int long long int
    // Write your code here.
    int low = 1, high = n, ans;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid * mid <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
#undef int
    return ans;
}
int main()
{
    return 0;
}