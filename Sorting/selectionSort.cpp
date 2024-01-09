#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x= y;
    y=temp;
}

void selectionSort(int arr[], int n) {
    
    for(int i =0 ;i<n-1;i++) 
    {   
    int swapindex = i;
        for(int j=i+1;j<n;j++) {
            if(arr[j] < arr[swapindex]) {
              
                swapindex = j;
            }
        }
        swap(arr[i], arr[swapindex]);
    }
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n; i++) {
        cout<<"Enter element "<<i<<" ";
        cin>>arr[i];
    }
    selectionSort(arr, n);
    for(int i = 0 ; i < n; i++) {
        cout<<arr[i]<<" ";
    }
   return 0;
}