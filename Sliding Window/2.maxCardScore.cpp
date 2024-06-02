#include <bits/stdc++.h>
using namespace std;
int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int l = n - k, r = n - 1;
    int sum = 0;
    for (int i = l; i < n; i++)
    {
        sum += cardPoints[i];
    }
    int maxi = sum;

    bool start = true;

    while (r < k - 1 || start)
    {
        start = false;
        sum -= cardPoints[l];
        l++;
        l %= n;
        r++;
        r %= n;
        sum += cardPoints[r];
        maxi = max(maxi, sum);
    }
    return maxi;
}
int main()
{
    return 0;
}