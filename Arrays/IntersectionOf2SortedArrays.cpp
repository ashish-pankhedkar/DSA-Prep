#include <bits/stdc++.h>
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> inter;
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            inter.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return inter;
}
int main()
{
    return 0;
}