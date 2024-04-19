#include<bits/stdc++.h>
using namespace std;
int NthRoot(int n, int m) {
  
    // Write your code here.
    long long int low = 1, high =m,ans;
    while(low<=high) {
        long long int mid = (high+low)/2;
        long long int p = pow(mid,n);
        // cout<<low<<" "<<high<<" "<<mid<<" "<<p<<endl;
        if(p == m ) {
            return mid;
        }
        else if(p > m || p<0){
            high = mid-1;
        }
        else {
          low = mid+1;
        }
    }
        return -1;
}
int main(){
   return 0;
}