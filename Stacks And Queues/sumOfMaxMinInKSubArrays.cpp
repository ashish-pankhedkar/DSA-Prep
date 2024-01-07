#include <bits/stdc++.h>
using namespace std;
int sumOf(vector<int> arr, int k)
{
    int ans = 0;
    int n = arr.size();

    deque<int> maxi(k);
    deque<int> mini(k);

    // add first window
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }

        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }

    for (int i = k; i < n; i++)
    {
        ans += arr[mini.front()] + arr[maxi.front()];

        // nextwindow
        while (!maxi.empty() && maxi.front() <= i - k)
        {
            maxi.pop_front();
        }

        while (!mini.empty() && mini.front() <= i - k)
        {
            mini.pop_front();
        }

        while (!maxi.empty() && arr[maxi.front()] <= arr[i])
        {
            maxi.pop_front();
        }

        while (!mini.empty() && arr[mini.front()] >= arr[i])
        {
            mini.pop_front();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }

    ans += arr[mini.front()] + arr[maxi.front()];

    return ans;
}
int main()
{
    vector<int> check = {1, 2, 3, 4, 5};
    cout << sumOf(check, 1);
    return 0;
}