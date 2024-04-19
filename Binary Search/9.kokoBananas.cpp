#include <bits/stdc++.h>
using namespace std;
bool canfinish(vector<int> &piles, int k, int h)
{
    int total_time = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        total_time += ceil((double)piles[i] / k);
        if (total_time > h)
            return false;
    }
    return true;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int maxi = 0;
    for (auto it : piles)
    {
        maxi = max(maxi, it);
    }

    int low = 1, high = maxi, mini = maxi;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canfinish(piles, mid, h))
        {
            // high = mid;
            high = mid - 1;
            mini = mid;
            // cout<<" can finish "<<endl;
        }
        else
        {
            low = mid + 1;
            // cout<<" cant finish "<<endl;
        }
    }
    return mini;
}
int main()
{
    return 0;
}