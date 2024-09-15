#include<bits/stdc++.h>
using namespace std;
bool checkIBit(int n, int i){
        return ( n & (1<<i));
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        int subsets = 1<<n;
        for(int i=0; i<subsets ; i++){
            vector<int> subset;
            for(int j=0;j<n;j++){
                if(checkIBit(i,j)){
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
int main(){
   
   return 0;
}