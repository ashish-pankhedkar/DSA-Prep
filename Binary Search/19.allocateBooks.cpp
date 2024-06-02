#include <bits/stdc++.h>
using namespace std;
int canAllocate(vector<int> &arr, int pages)
{
    // cout<<"For mini pages : "<<pages<<endl;
    int stud = 1;
    int prevAllocated = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (prevAllocated + arr[i] <= pages)
        {
            prevAllocated += arr[i];
        }
        else
        {
            prevAllocated = arr[i];
            stud++;
        }
        // cout<<stud<<" -> "<<arr[i]<<endl;
    }
    // cout<<"Total stud : " <<stud<<endl;
    return stud;
}

int findPages(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;
    // Write your code here.
    int maxi = 0, sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
        sum += arr[i];
    }

    int low = maxi, high = sum, ans = -1;

    while (low <= high)
    {
        int mid = (high - low) / 2 + low;
        // cout<<low<<" "<<high<<" "<<mid<<" "<<ans<<endl;
        int stud = canAllocate(arr, mid);
        if (stud > m)
        {
            low = mid + 1;
        }
        else
        {   ans = mid; // check book for explaination
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    return 0;
}