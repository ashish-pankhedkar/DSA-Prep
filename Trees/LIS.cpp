#include <bits/stdc++.h>
using namespace std;

void LIS(vector<int> adj[], int node, set<int> &visited, set<int> &ans)
{
    visited.insert(node);
    ans.insert(node);

    for (auto it : adj[node])
    {
        if (visited.find(it) == visited.end())
        {
            visited.insert(it);
            if (it > node)
            {
                LIS(adj, it, visited, ans);
            }
        }
    }
}

int get_ans(int n, int m, vector<int> parent) {
 
  

    vector<int> dp(n,1);
    for(int i=0;i<m;i++) {
        dp[parent[i]-1] = 0;
    }

    for(int i = 0 ; i <n ; i++) {
        for(int )
    }


    for(int )


}
int main()
{

    int n , m;
    cout<<"Input"<<endl;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int p;
        cin>>p;
        adj[p-1].push_back(i);
    }
    int total =0;

    for(int i=0;i<n;i++){
        set<int> s;
        set<int> visited;
        LIS(adj,i,visited,s);
        total+=s.size();
        total%=10000000007;

    }
    cout<<total;

    return 0;
}