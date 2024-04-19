#include <bits/stdc++.h>
using namespace std;
int upperBound(vector<int> arr, int target)
{
    int n = arr.size();
    int ans = n, low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = high + (low - high) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{   
    vector<int> arr = {1,2,3,4,5,8,8,10,10,11};
    cout<< upperBound(arr, 9);
    return 0;
}