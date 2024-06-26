#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    
    int left = low;     
    int right = mid + 1; 
   
    int cnt = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

   
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0;
    int count = 0;
    int mid = (low + high) / 2;
    count += mergeSort(arr, low, mid);     
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count; 
}
int numberOfInversions(vector<int> &a, int n)
{
    // Write your code here.
    return mergeSort(a, 0, n - 1);
}
int main()
{
    return 0;
}