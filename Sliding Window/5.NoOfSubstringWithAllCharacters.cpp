#include <bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s)
{
    int n = s.size();
    int c = 0;
    int hash[3] = {-1, -1, -1};
    for (int i = 0; i < n; i++)
    {
        hash[s[i] - 'a'] = i;
        int lastIndex = min(hash[0], min(hash[1], hash[2]));
        if (lastIndex != -1)
        {
            c = c + lastIndex + 1;
        }
    }
    return c;
}
int main()
{
    return 0;
}