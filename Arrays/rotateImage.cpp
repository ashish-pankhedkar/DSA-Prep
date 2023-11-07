#include <bits/stdc++.h>
using namespace std;
void swap(int i, int j, int n, vector<vector<int>> &matrix)
{
    int temp = matrix[i][j];
    matrix[i][j] = matrix[n - 1 - j][i];
    matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
    matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
    matrix[j][n - 1 - i] = temp;
}
void rotate_SWAP(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i <= n / 2; i++)
    {
        for (int j = i; j < n - 1 - i; j++)
        {
            swap(i, j, n, matrix);
        }
    }
}

void rotate_TRANSPOSE(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main()
{
    return 0;
}