#include <bits/stdc++.h>
using namespace std;
int minBitFlips(int start, int goal)
{
    int xr = (start ^ goal);
    return __builtin_popcount(xr);
}
int main()
{
    return 0;
}