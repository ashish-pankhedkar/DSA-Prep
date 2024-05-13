#include <bits/stdc++.h>
using namespace std;
int noof1s(vector<int> &row, int n)
{
    int low = 0;
    int high = n - 1;
    int ind = -1;
    while (low <= high)
    {
        int mid = (high - low) / 2 + low;
        if (row[mid] == 1)
        {
            ind = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    int ones = ind == -1 ? 0 : n - ind;
    return ones;
}
int rowWithMax1s(vector<vector<int>> mat, int n, int m)
{
    // code here

    int maxrow = -1;
    int max1 = -1;
    for (int i = 0; i < n; i++)
    {
        int no1s = noof1s(mat[i], m);
        if (no1s > max1)
        {
            max1 = no1s;
            maxrow = i;
        }
        // cout<<i<<" : Number of ones : "<<no1s<<" Current max 1s : "<<max1<<" Current Max row : "<<maxrow<<endl;
    }

    return max1 == 0 ? -1 : maxrow;
}
int main()
{
    return 0;
}