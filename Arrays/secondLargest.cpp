#include <bits/stdc++.h>
using namespace std;
int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
    int slargest = INT_MIN;
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > slargest && arr[i] != largest)
        {
            slargest = arr[i];
        }
    }

    return slargest == INT_MIN ? -1 : slargest;
}
int main()
{
    return 0;
}