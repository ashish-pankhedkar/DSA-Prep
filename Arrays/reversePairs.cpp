#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

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
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int countpair(int low, int mid, int high, vector<int> &arr)
{
    int right = mid + 1;
    int count = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && long(arr[i]) - long(arr[right]) > long(arr[right]))
            right++;

        count += (right - (mid + 1));
    }
    return count;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low >= high)
        return 0;
    int mid = (low + high) / 2;
    count += mergeSort(arr, low, mid);      // left half
    count += mergeSort(arr, mid + 1, high); // right half
    count += countpair(low, mid, high, arr);
    merge(arr, low, mid, high); // merging sorted halves
    return count;
}
int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}
int main()
{
    return 0;
}