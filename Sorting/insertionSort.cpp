#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
{
    // code here
    for (int i = 1; i < n; i++)
    {
        int ind = i - 1; 
        while (ind >= 0 && arr[ind] > arr[ind + 1])
        {
            int temp = arr[ind];
            arr[ind] = arr[ind + 1];
            arr[ind + 1] = temp;
            ind--;
        }
    }
}
int main()
{
    return 0;
}