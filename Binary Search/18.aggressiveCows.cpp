#include <bits/stdc++.h>
using namespace std;
bool canPlace(int n, vector<int> arr, int cows, int d)
{
    int lastplaced = 0;
    for (int i = 0; i < n; i++)
    {

        if (i == 0)
        {
            cows--;
            if (cows == 0)
                return true;
            continue;
        }

        int currd = arr[i] - arr[lastplaced];
        if (currd >= d)
        {
            cows--;
            if (cows == 0)
                return true;
            lastplaced = i;
        }
    }
    return false;
}

int solve(int n, int cows, vector<int> &arr)
{

    // Write your code here

    sort(arr.begin(), arr.end());

    int low = 0;
    int high = (arr[n - 1] - arr[0]);
    int ans = 0;

    while (low <= high)
    {
        int mid = (high - low) / 2 + low;

        if (canPlace(n, arr, cows, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        // cout<<mid<<" "<<ans<<endl;
    }
    return ans;
}
int main()
{
    return 0;
}