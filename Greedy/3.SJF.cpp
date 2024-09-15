#include <bits/stdc++.h>
using namespace std;
long long solve(vector<int> &bt)
{
    // code here
    sort(bt.begin(), bt.end());
    int wait = 0, total = 0;
    for (int i = 0; i < bt.size(); i++)
    {
        wait += total;
        total += bt[i];
    }
    return (wait / bt.size());
}
int main()
{
    return 0;
}