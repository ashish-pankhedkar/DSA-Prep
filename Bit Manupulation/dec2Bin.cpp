#include<bits/stdc++.h>
using namespace std;
string dec2bin(int x){
    string bi = "";
    while(x){
        bi+=to_string(x%2);
        x/=2;
    }
    reverse(bi.begin(), bi.end());
    return bi;

}

int bin2dec(string x) {
    int len = x.length();
    int p2 = 1;
    int ans = 0;
    for(int i= len -1; i>=0;i--){
        if(x[i]== '1') ans+=p2;
        p2*=2;
    }
    return ans;
}
int main(){
    // cout<<dec2bin(45);
    cout<<bin2dec("11011");
   return 0;
}