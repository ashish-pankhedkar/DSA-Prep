#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
    unordered_map<char, int> mp;
    for (auto it : t)
    {
        mp[it]++;
    }

    int l = 0, r = 0, mini = INT_MAX, cnt = 0, startI = -1;

    while (r < s.size())
    {
        if (mp[s[r]] > 0)
        {
            cnt++;
        }
        mp[s[r]]--;

        while (cnt == t.size())
        {
            if (r - l + 1 < mini)
            {
                startI = l;
                mini = r - l + 1;
            }
            mp[s[l]]++;
            if (mp[s[l]] > 0)
                cnt--;
            l++;
        }
        r++;
    }
    return startI == -1 ? "" : s.substr(startI, mini);
}
int main()
{
    return 0;
}