#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
    // Your code here
    int ar[r - l + 1];
    int left = l;
    int right = m + 1;
    int ind = 0;
    while (left <= m && right <= r)
    {
        if (arr[left] < arr[right])
        {
            ar[ind] = arr[left];
            left++;
        }
        else
        {
            ar[ind] = arr[right];
            right++;
        }
        ind++;
    }

    while (left <= m)
    {
        ar[ind] = arr[left];
        left++;
        ind++;
    }
    while (right <= r)
    {
        ar[ind] = arr[right];
        right++;
        ind++;
    }

    for (int i = 0; i <= r - l; i++)
    {
        arr[l + i] = ar[i];
    }
}


void mergeSort(int arr[], int l, int r)
{
    // code here
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
int main()
{
    return 0;
}