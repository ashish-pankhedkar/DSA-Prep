#include <bits/stdc++.h>
using namespace std;
int longestKSubstr(string s, int k)
{
    // your code here
    int n = s.size();
    unordered_map<char, int> mp;
    int maxi = 0;
    int l = 0, r = 0;
    while (r < n)
    {

        mp[s[r]]++;
        if (mp.size() >= k)
        {
            while (mp.size() > k)
            {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            maxi = max(maxi, r - l + 1);
        }
        r++;
    }
    return maxi == 0 ? -1 : maxi;
}
int main()
{
    return 0;
}