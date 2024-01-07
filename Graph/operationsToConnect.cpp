#include <bits/stdc++.h>
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

    void uniounByRank(int u, int v)
    {
        int uu = findUltimatePar(u);
        int uv = findUltimatePar(v);

        if (uu == uv)
        {
            return;
        }
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
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSet ds(n);
        int extras = 0;
        for (auto it : connections)
        {
            if (ds.findUltimatePar(it[0]) == ds.findUltimatePar(it[1]))
            {
                extras++;
            }
            else
            {
                ds.uniounByRank(it[0], it[1]);
            }
        }

        int components = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == ds.findUltimatePar(i))
                components++;
        }

        return (extras >= components - 1) ? components - 1 : -1;
    }
};
int main()
{
    return 0;
}