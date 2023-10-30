#include <bits/stdc++.h>
using namespace std;
vector<int> sortedArray(vector<int> a, vector<int> b)
{
    // Write your code here
    vector<int> unin;
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (unin.size() == 0 || unin.back() != a[i])
            {
                unin.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (unin.size() == 0 || unin.back() != b[j])
            {
                unin.push_back(b[j]);
            }
            j++;
        }
    }

    while (j < n2)
    {
        if (unin.size() == 0 || unin.back() != b[j])
        {
            unin.push_back(b[j]);
        }
        j++;
    }

    while (i < n1)
    {
        if (unin.size() == 0 || unin.back() != a[i])
        {
            unin.push_back(a[i]);
        }
        i++;
    }

    return unin;
}
int main()
{
    return 0;
}