#include<bits/stdc++.h>
using namespace std;
string longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = (1 + dp[i - 1][j - 1]);
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int len =  dp[n][m];
    string ans(len,'$');
    int index = len-1;
    int i=n,j=m;
    while(i> 0 && j>0) {
        if(text1[i-1] == text2[j-1]) {
            ans[index] = text1[i-1];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i=i-1;
        }
        else {
            j=j-1;
        }
    }
    return ans;
}
int main(){
    string s1,s2;
    cout<<"Enter 2 strings : ";
    cin>>s1>>s2;
    cout<<longestCommonSubsequence(s1,s2);
   return 0;
}