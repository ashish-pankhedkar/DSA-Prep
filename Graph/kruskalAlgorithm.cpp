#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltimatePar(int node)
    {
        if (node == parent[node])
            return node;
        // path compression
        return parent[node] = findUltimatePar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int uu = findUltimatePar(u);
        int uv = findUltimatePar(v);

        if (uu == uv)
            return;

        else if (rank[uu] < rank[uv])
        {
            parent[uu] = uv;
        }
        else if (rank[uv] < rank[uu])
        {
            parent[uv] = uu;
        }
        else
        {
            parent[uv] = uu;
            rank[uu]++;
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++) {
            for(auto it: adj[i]) {
                edges.push_back({it[1],{it[0],i}});
            }
        }
        
        
        sort(edges.begin(), edges.end());
        int mstwt = 0;
        DisjointSet ds(V);
        
        for(auto it: edges) {
            int wt= it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUltimatePar(u)!= ds.findUltimatePar(v)) {
                mstwt+=wt;
                ds.unionByRank(u,v);
                
            }
            
        }
        return mstwt;
    }
};
int main(){
   return 0;
}