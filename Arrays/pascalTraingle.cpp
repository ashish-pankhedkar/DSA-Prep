#include<bits/stdc++.h>
using namespace std;
long long funcNCR(int n, int r) {
    long long res= 1;
    for(int i=0;i<r;i++) {
        res*=(n-i);
        res/=(i+1);
    }

    return res;
}

long long getPascalElement(int row, int col) {
    return funcNCR(row-1,col-1);
}

vector<long long> getPascalRow(int row) {
    vector<long long> ans;
    ans.push_back(1);
    if(row ==1) return ans; 
    long long ele = 1;
    for(int i=2;i<row;i++) {
        ele*=(row+1-i);
        ele/=(i-1);
        ans.push_back(ele);
    }
    ans.push_back(1);
    return ans;
}

vector<vector<long long>> getPascalTraingle(int row) {
    vector<vector<long long>> ans;
    for(int i=0;i<row;i++) {
        ans.push_back(getPascalRow(i+1));
    }
    return ans;
}




int main(){

    int choice;
    cout<<"Enter Operation : "<<endl;
    cout<<"0 : Pascal Number using row & col"<<endl;
    cout<<"1 : Pascal Row using row number"<<endl;
    cout<<"2 : Complete Pascal Triangle till given row"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 0:
       { int row, col;
        cout<<"Enter row : ";
        cin>>row;
        cout<<"Enter col : ";
        cin>>col;
        cout<<"The element at : "<<row<<","<<col<<" is : "<<getPascalElement(row,col);
        break;}

    case 1 :
        {int row;
        cout<<"Enter row to print : ";
        cin>>row;
        vector<long long> ans = getPascalRow(row);
        cout<<"The "<<row<<" row is : ";
        for(int i=0;i<row;i++) {
            cout<<ans[i]<<" ";
        }
        break;}

    case 2 :
        {int row;
        cout<<"Enter the row till which traingle should be printed : ";
        cin>>row;
        vector<vector<long long>> ans = getPascalTraingle(row);
        cout<<"The pascal Triangle till "<<row<<" is :"<<endl;
        for(int i=0;i<row;i++) {
            for(int j=0;j<=i;j++) {
                cout<<ans[i][j]<<"\t";
            }
            cout<<endl;
        } 
    }
    default:
        break;
    }
   return 0;
}