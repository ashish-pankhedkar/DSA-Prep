#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int d = 0;
    int top = 0;
    int bot = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;
    vector<int> ans;
    while (top <= bot && left <= right)
    {

        if (d == 0)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            d = 1;
        }
        else if (d == 1)
        {
            for (int i = top; i <= bot; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            d = 2;
        }
        else if (d == 2)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bot][i]);
            }
            bot--;
            d = 3;
        }
        else
        {
            for (int i = bot; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
            d = 0;
        }
    }
    return ans;
}
int main()
{
    return 0;
}