#include<bits/stdc++.h>
using namespace std;

int fib_MEMOIZATION(int n, vector<int> &dp) {
    if(n<=1) return dp[n] = n;

    if(dp[n]!=-1) return dp[n];
    else {
        return dp[n] = fib_MEMOIZATION(n-1,dp) +fib_MEMOIZATION(n-2,dp);
    }
}

int fib_TABULATION(int n) {
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i =2;i<=n;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n-1];
}

int fib_SO(int n) {
    int prev = 0;
    int pprev = 1;
    int curri;
    for(int i =2;i<=n;i++) {
     curri = prev + pprev;
     pprev = prev;
     prev = curri;

    }

    return curri;
}
int main(){
    int n;
    cout<<"To calc nth term Enter n: ";
    cin>>n;
  
    cout<<n<< "th Term is : " <<  fib_SO(n);;
   return 0;
}