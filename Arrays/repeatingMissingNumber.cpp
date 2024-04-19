#include <bits/stdc++.h>
using namespace std;

// Insane solution
vector<int> findTwoElement(vector<int> arr, int n)
{
    // code here
    for (int i = 0; i < n; i++)
        arr[i]--;
    for (int i = 0; i < n; i++)
    {
        int a = (arr[i] % n);
        arr[a] += n;
    }

    vector<int> ans(2);
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] / n) == 0)
            ans[1] = i + 1;
        if ((arr[i] / n) == 2)
            ans[0] = i + 1;
    }
    return ans;
}

// hashing approach
vector<int> findTwoElement(vector<int> arr, int n)
{
    vector<int> hash(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    vector<int> res(2, 0);
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
            res[0] = i;
        if (hash[i] == 0)
            res[1] = i;
    }

    return res;
    // code here
}
int main()
{
    return 0;
}