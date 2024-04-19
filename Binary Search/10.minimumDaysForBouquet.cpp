#include <bits/stdc++.h>
using namespace std;
bool canmake(vector<int> &bloomday, int day, int k, int m)
{
    int count = 0, bou = 0;
    for (int it : bloomday)
    {
        if (it <= day)
            count++;
        else
        {
            bou += (count / k);
            count = 0;
        }
    }
    bou += (count / k);

    return bou >= m;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    int mini = INT_MAX, maxi = 0;
    for (int &it : bloomDay)
    {
        mini = min(mini, it);
        maxi = max(maxi, it);
    }

    if (m > bloomDay.size() / k)
        return -1;

    int low = mini, high = maxi, minday = maxi;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canmake(bloomDay, mid, k, m))
        {
            minday = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return minday;
}
int main()
{
    return 0;
}