#include <bits/stdc++.h>
using namespace std;
// Here matrix rows and columns are indiviually sorted.
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int r = 0, c = m - 1;

    while (r < n && c >= 0)
    {
        if (matrix[r][c] == target)
            return true;
        else if (target > matrix[r][c])
            r++;
        else
            c--;
    }

    return false;
}
int main()
{
    return 0;
}