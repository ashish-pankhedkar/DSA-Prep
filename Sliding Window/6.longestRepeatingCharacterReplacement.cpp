#include <bits/stdc++.h>
using namespace std;

int characterReplacement_OPTMI(string s, int k)
{
    int n = s.size();
        int l =0, r=0, maxf = 0, maxi =0;
        unordered_map<char,int> mp;

        while(r < n) {
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);

            if((r-l+1 - maxf) > k) {
                mp[s[l]]--;
                l++;
                // maxf = 0;
                // for(auto &it : mp){
                //     maxf = max(maxf, it.second);
                // }

            }
            if((r-l+1 - maxf) <= k)
            maxi = max(maxi,r-l+1);
            r++;
         }

         return maxi;
}

int characterReplacement(string s, int k)
{
    int n = s.size();
    int l = 0, r = 0, maxf = 0, maxi = 0;
    unordered_map<char, int> mp;

    while (r < n)
    {
        mp[s[r]]++;
        maxf = max(maxf, mp[s[r]]);

        while ((r - l + 1 - maxf) > k)
        {
            mp[s[l]]--;
            l++;
            maxf = 0;
            for (auto &it : mp)
            {
                maxf = max(maxf, it.second);
            }
        }
        maxi = max(maxi, r - l + 1);
        r++;
    }

    return maxi;
}
int main()
{
    return 0;
}