#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n)
{
    // Your code here
    for (int i = n - 1; i > 0; i--)
    {   bool swap = false;
        for (int j = 0; j < i; j++)
        {   
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = true;
            }
        }
        if(!swap) return;
    }
}
int main()
{
    return 0;
}