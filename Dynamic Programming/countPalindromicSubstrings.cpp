#include <bits/stdc++.h>
using namespace std;
int countSubstrings(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case if i<=j then it is palindrom
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i >= j)
                dp[i][j] = 1;
        }
    }


    //update the other half of matrix

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            int row = j;
            int col = j + i;

            if (s[row] == s[col] && dp[row + 1][col - 1] == 1)
                dp[row][col] = 1;
            else
            {
                dp[row][col] = 0;
            }
            // cout<<"("<<row<<","<<col<<") ";
        }
        // cout<<endl;
    }
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (dp[i][j])
                count++;
        }
    }
    return count;

}
int main()
{
    return 0;
}