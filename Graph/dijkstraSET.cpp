#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    set<pair<int, int>> st;
    st.insert({0, S});

    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    while (!st.empty())
    {
        auto curr = *(st.begin());
        int currdist = (*(st.begin())).first;
        int currnode = curr.second;
        st.erase(st.begin());

        dist[currnode] = min(dist[currnode], currdist);

        for (auto it : adj[currnode])
        {
            int adjnode = it[0];
            int adjwt = it[1];

            if (dist[adjnode] > (currdist + adjwt))
            {
                st.erase({dist[adjnode], adjnode});
                st.insert({currdist + adjwt, adjnode});
            }
        }
    }

    return dist;
}
int main()
{
    return 0;
}