#include <bits/stdc++.h>
using namespace std;
bool search(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return true;
        // left is sorted
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= target && arr[mid] >= target)
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        // right sorted
        else
        {
            if (arr[mid] <= target && arr[high] >= target)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
    }

    return false;
}
int main()
{
    return 0;
}