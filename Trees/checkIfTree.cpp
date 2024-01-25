#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool dfs(int src, vector<int> adj[], int vis[], int pathVis[])
{
    vis[src] = 1;
    pathVis[src] = 1;

    for (auto it : adj[src])
    {
        if (!vis[it])
        {
            if (dfs(it, adj, vis, pathVis))
                return true;
        }
        else if (pathVis[it])
        {
            return true;
        }
    }

    pathVis[src] = 0;
    return false;
}




int main() {
    vector<pair<int,int>> p;

    unordered_set<int> s;
    for(auto it: p) {
        s.insert(it.first);
        s.insert(it.second);
    }
    int n = s.size();
    vector<int> adj[n];
    int indegree[n] = {0};
    int outdegree[n] = {0};

    for(auto it : p) {
        adj[it.second].push_back(it.first);
        outdegree[it.second]++;
        indegree[it.first]++;
    }
    //indegree check
    int root = -1;
    for(int i=0;i<n;i++){
        if(indegree[i] >1 ||( indegree[i]==0 && root!=-1 )) return false;
        else if(indegree[i]==0) root=i;
    }
    if(root==-1) return false;

    //outdegree check

    for(int i=0;i<n;i++) {
        if(outdegree[i] > 2) return false;
    }

    //cyclic check
    int pathVis[n]= {0};
    int vis[n] = {0};

    if(dfs(root,adj,vis,pathVis)) return false;

    for(int i=0;i<n;i++) {
        if(vis[i]==0)
        return false;
    }
    return true;
}