#include <bits/stdc++.h>
using namespace std;
void shortest_distance(vector<vector<int>> &matrix)
{
    // Code here

    int n = matrix.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k] == -1 || matrix[k][j] == -1)
                    continue;
                else
                {
                    int newCost = matrix[i][k] + matrix[k][j];
                    if (matrix[i][j] != -1)
                    {
                        matrix[i][j] = min(matrix[i][j], newCost);
                    }
                    else
                    {
                        matrix[i][j] = newCost;
                    }
                }
            }
        }
    }
}
int main()
{
    return 0;
}