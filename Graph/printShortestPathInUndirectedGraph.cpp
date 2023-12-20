#include<bits/stdc++.h>
using namespace std;
//Q: zero based indexed undirected graph with weights. Print the shortest path from src to des
vector<int> shortestPath(int src, int dest, vector<vector<int>> &edges, int n) {
    //create adj list
    vector<pair<int,int>> adj[n];
    for(auto it: edges) {
        // node -> {adjNode, wt}
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

  
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});

    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    vector<int> parents(n);
    parents[src] = src;


    while(!pq.empty()) {
        int currNode = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        for(auto it: adj[currNode]) {
            int ver = it.first;
            int wt = it.second;
            int newDist = currDist + wt;
            if(dist[ver] > newDist) {
                pq.push({newDist, ver});
                dist[ver] = newDist;
                parents[ver]=currNode;
            }
        }
    }

    vector<int> ans;
    int curr = dest;

    while(dest != parents[dest]) {
        ans.push_back(dest);
        dest = parents[dest];
    }
    ans.push_back(src);

    reverse(ans.begin(), ans.end());
    return ans;
    


}
int main(){

    vector<vector<int>> edges = {
        {0,1,4},
        {0,2,4},
        {1,2,2},
        {2,3,3},
        {2,5,6},
        {2,4,1},
        {3,5,2},
        {4,5,3}
    };
  for(int i=1;i<6;i++)
    {vector<int> result = shortestPath(0,i,edges,6);
    cout<<"Shortest Path from 0 to "<<i<<endl; 

    for(int i=0;i<result.size();i++) {
        cout<<result[i]<<" --> ";
    }
    cout<<endl;}
    return 0;
}