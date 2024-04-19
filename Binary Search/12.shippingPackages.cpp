#include <bits/stdc++.h>
using namespace std;
bool canship(vector<int> &weights, int cap, int days)
{
    int daysneeded = 1, currweight = 0;
    for (int i = 0; i < weights.size(); i++)
    {

        if (daysneeded > days)
            return false;

        if (currweight + weights[i] > cap)
        {
            currweight = weights[i];
            daysneeded++;
        }
        else
        {
            currweight += weights[i];
        }
    }

    return daysneeded <= days;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int sum = 0, largest = 0;
    for (int it : weights)
    {
        sum += it;
        largest = max(largest, it);
    }

    int low = largest, high = sum, mini = sum;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canship(weights, mid, days))
        {
            mini = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return mini;
}
int main()
{
    return 0;
}