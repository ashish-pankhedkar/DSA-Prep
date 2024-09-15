#include <bits/stdc++.h>
using namespace std;
int findstations(vector<int> &stations, double dist)
{
    int st = 0;

    for (int i = 0; i < stations.size() - 1; i++)
    {
        //   int needed = (stations[i+1] - stations[i])/dist;
        //   if(needed * dist == (double)(stations[i+1]- stations[i])){
        //       needed--;
        //   }
        st += ceil(((double)stations[i + 1] - (double)stations[i]) / dist) - 1;
    }
    return st;
}
double findSmallestMaxDist(vector<int> &stations, int k)
{
    // Code here
    double low = 0.0, high = 0.0;
    for (int i = 0; i < stations.size() - 1; i++)
    {
        high = max(high, (double)(stations[i + 1] - stations[i]));
    }

    double ans = high;
    while (high - low > 1e-4)
    {

        double mid = (high + low) / 2.0;
        // cout<<low<<" "<<mid<<" "<<high<<" "<<ans<<endl;
        int st = findstations(stations, mid);
        if (st > k)
        {
            low = mid;
        }
        else
        {
            ans = mid;
            high = mid;
        }
    }
    return ans;
}
int main()
{
    return 0;
}