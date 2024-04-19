#include <bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int> &arr, int k)
{
    vector<int> ans;
    int ind = 0, currele = 1;
    while (ind < arr.size())
    {
        if (arr[ind] == currele)
        {
            ind++;
        }
        else
        {
            ans.push_back(currele);
        }
        currele++;
    }

    if (ans.size() >= k)
    {
        return ans[k - 1];
    }
    else
    {
        return arr[arr.size() - 1] + (k - ans.size());
    }
}
int main()
{
    return 0;
}