#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxi = 0;
    int counter = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            counter++;
            maxi = max(maxi, counter);
        }
        else
            counter = 0;
    }
    return maxi;
}
int main()
{   int s;
    cout<<"Enter array size : "<<endl;
    cin>>s;
    vector<int> arr(s);
    for(int i=0;i<s;i++) {
        cout<<"Enter Number 0 or 1 :";
        cin>>arr[i];
        cout<<endl;
    }
    int ans = findMaxConsecutiveOnes(arr);
    cout<<"Max conse Ones are : "<<ans;
    return 0;
}