#include <bits/stdc++.h>
using namespace std;
string minWindow(string str1, string str2)
{
    // Write your Code here
    int l = 0, r = 0, k = 0, mini = INT_MAX, start = -1;

    while (r < str1.length())
    {
        // cout<<l<<" "<<r<<" "<<k<<endl;
        if (str1[r] == str2[k])
            k++;

        if (k == str2.length())
        {
            l = r;
            k--;

            while (l >= 0 && k >= 0)
            {
                if (str1[l] == str2[k])
                {
                    k--;
                }
                l--;
            }
            l++;
            if (mini > r - l + 1)
            {
                mini = r - l + 1;
                start = l;
            }
            k = 0;
            r = l;
        }
        r++;
    }

    return start == -1 ? "" : str1.substr(start, mini);
}
int main()
{
    return 0;
}