#include <bits/stdc++.h>
using namespace std;
int findPlatform(int arr[], int dep[], int n)
{
    // Your code here

    sort(arr, arr + n);
    sort(dep, dep + n);

    int stations = 0;
    int r = 0;
    int empty = 0;

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        // cout<<stations<<" "<<empty<<" "<<r<<endl;

        while (r < n && dep[r] < curr)
        {
            r++;
            empty++;
        }

        if (empty == 0)
            stations++;
        else
            empty--;
    }
    return stations;
}
int main()
{
    return 0;
}