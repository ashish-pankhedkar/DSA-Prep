#include <bits/stdc++.h>
using namespace std;
int remove_duplicate(int arr[], int n)
{
    // code here
    int diff = 1;
    for (int i = 0, j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            i++;
            arr[i] = arr[j];
            diff++;
        }
    }
    return diff;
}
int main()
{
    return 0;
}