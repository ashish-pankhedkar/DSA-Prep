#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK_POSITIVEOPTIMAL(vector<int> a, long long k)
{
    // Write your code here
    int maxi = 0;
    int start = 0;
    int end = 0;
    long long sum = a[0];
    int n = a.size();
    while (end < n)
    {
        while (start <= end && sum > k)
        {
            sum -= a[start];
            start++;
        }
        if (sum == k)
        {
            maxi = max(maxi, end - start + 1);
        }
        end++;
        if (end < n)
            sum += a[end];
    }

    return maxi;
}
int longestSubarrayWithSumK_HASHINGAPPROACH(vector<int> A, long long K)
{
    // Write your code here
    int maxi = 0;
    long long sum = 0;
    unordered_map<long long, int> track;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if (track.find(sum) == track.end()) // updating if it is not present since we want smallest index
        {
            track[sum] = i;
        }
        if (sum == K)
        {
            maxi = max(maxi, i + 1);
        }
        else if (track.find(sum - K) != track.end())
        {
            maxi = max(maxi, i - track[sum - K]);
        }
    }
    return maxi;
}
int main()
{
    return 0;
}