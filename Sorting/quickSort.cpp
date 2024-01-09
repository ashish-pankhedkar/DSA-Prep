#include <bits/stdc++.h>
using namespace std;
void quickSort(int arr[], int low, int high)
{
    // code here
    if (low < high)
    {
        int pindex = partition(arr, low, high);
        quickSort(arr, low, pindex - 1);
        quickSort(arr, pindex + 1, high);
    }
}

public:
int partition(int arr[], int low, int high)
{
    // Your code here

    int pivot = low;
    int i = low, j = high;
    while (i < j)
    {
        while (i <= high - 1 && arr[i] <= arr[pivot])
            i++;
        while (j >= low + 1 && arr[j] >= arr[pivot])
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[pivot], arr[j]);
    return j;
}
int main()
{
    return 0;
}