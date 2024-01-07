#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
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

int main()
{
    DisjointSet ds(7);
    ds.uniounByRank(1, 2);
    ds.uniounByRank(2, 3);
    ds.uniounByRank(4, 5);
    ds.uniounByRank(6, 7);
    ds.uniounByRank(5, 6);
    ds.uniounByRank(3, 7);

    return 0;
}