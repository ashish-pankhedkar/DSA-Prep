#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

double findSmallestMaxDist(vector<int> &stations, int k)
{
    // Code here
    priority_queue<pair<double, int>> pq;

    int n = stations.size();
    vector<double> newst(n - 1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        double diff = (double)stations[i + 1] - (double)stations[i];
        pq.push({diff, i});
    }

    for (int i = 0; i < k; i++)
    {
        double maxDist = pq.top().first;
        int ind = pq.top().second;
        pq.pop();

        newst[ind]++;
        double seclen = (double)(stations[ind + 1] - stations[ind]) / (double)(newst[ind] + 1);

        pq.push({seclen, ind});
    }

    double maxi = 0;
    for (int i = 0; i < n - 1; i++)
    {
        double seclen = (double)(stations[i + 1] - stations[i]) / (double)(newst[i] + 1);
        maxi = max(maxi, seclen);
    }

    return maxi;
}
int main()
{
    return 0;
}