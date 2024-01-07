#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> ans;
    deque<int> maxi(k);

    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] < arr[i])
            maxi.pop_back();

        maxi.push_back(i);
    }

    for (int i = k; i < n; i++)
    {
        ans.push_back(arr[maxi.front()]);

        while (!maxi.empty() && maxi.front() <= i - k)
            maxi.pop_front();

        while (!maxi.empty() && arr[maxi.back()] < arr[i])
            maxi.pop_back();
        maxi.push_back(i);
    }
    ans.push_back(arr[maxi.front()]);
    return ans;
}
int main()
{
    return 0;
}