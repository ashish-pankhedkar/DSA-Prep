#include <bits/stdc++.h>
using namespace std;
// Q  : Find the maximum length fo substring of form a*b*a* formed after deleting  characters from string s

// Here counter represents state of string 0 = a* 1= a*b* 2 =a*b*a

int findall(int counter, int index, string &s, vector<vector<int>> &dp)
{
    int n = s.size();
    if (index >= n)
        return 0;

    if (dp[counter][index] != -1)
        return dp[counter][index];

    int nottake = findall(counter, index + 1, s, dp);

    int take = 0;
    if (s[index] == 'a')
    {
        if (counter == 0)
            take = 1 + findall(0, index + 1, s, dp);
        if (counter == 1)
            take = 1 + findall(2, index + 1, s, dp);
        if (counter == 2)
            take = 1 + findall(2, index + 1, s, dp);
    }
    if (s[index] == 'b')
    {
        if (counter == 0)
            take = 1 + findall(1, index + 1, s, dp);
        if (counter == 1)
            take = 1 + findall(1, index + 1, s, dp);
        if (counter == 2)
            take = 0;
    }
    return dp[counter][index] = max(take, nottake);
}

int findLongestString(string s)
{

    int n = s.size();

    vector<vector<int>> dp(3, vector<int>(n, -1));

    findall(0, 0, s, dp);
    findall(1, 0, s, dp);
    findall(2, 0, s, dp);

    int maxi = -1;
    for (int i = 0; i <= 2; i++)
    {
        maxi = max(maxi, dp[i][0]);
    }
    return maxi;
}

signed main()
{

    string s = "aaaabbbbaaaaba";

    cout << "string is : " << s << endl;
    cout << "Ans is : ";
    cout << findLongestString(s);

    return 0;
}
int main()
{
    return 0;
}