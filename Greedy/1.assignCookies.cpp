#include <bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int count = 0;
    for (int l = 0, r = 0; l < s.size() && r < g.size(); l++)
    {
        if (s[l] >= g[r])
        {
            count++;
            r++;
        }
    }
    return count;
}
int main()
{
    return 0;
}