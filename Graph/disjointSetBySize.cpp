#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 0);
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

    void uniounBySize(int u, int v)
    {
        int uu = findUltimatePar(u);
        int uv = findUltimatePar(v);

        if (uu == uv)
            return;

        else if (size[uu] < size[uv])
        {
            parent[uu] = uv;
            size[uv]+=size[uu];
        }
        else
        {
            parent[uv] = uu;
            size[uu]+=size[uv];
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.uniounBySize(1, 2);
    ds.uniounBySize(2, 3);
    ds.uniounBySize(4, 5);
    ds.uniounBySize(6, 7);
    ds.uniounBySize(5, 6);
    if(ds.findUltimatePar(3)!=ds.findUltimatePar(7)) 
    {
        cout<<"Different component ";
    }
    ds.uniounBySize(3, 7);
    if(ds.findUltimatePar(3) == ds.findUltimatePar(7)) 
    {
        cout<<"Same component";
    }

    return 0;
}