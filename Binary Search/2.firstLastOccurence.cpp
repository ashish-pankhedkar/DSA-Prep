#include <bits/stdc++.h>
using namespace std;
pair<long, long> indexes(vector<long long> arr, long long x)
{
    // code here
    int n = arr.size();
    int lo = 0;
    int hi = n - 1;
    int fi = -1;
    int li = -1;
    int mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (arr[mid] == x)
        {
            hi = mid - 1;
            fi = mid;
        }
        else if (arr[mid] > x)
        {
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    lo = 0;
    hi = n - 1;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (arr[mid] == x)
        {
            lo = mid + 1;
            li = mid;
        }
        else if (arr[mid] > x)
        {
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    return {fi, li};
}
int main()
{
    return 0;
}