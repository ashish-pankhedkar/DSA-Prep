#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
// histogram problem solution
    void nextSmallerElement(vector<int> &next, vector<int> heights, int n)
    {
        stack<int> s;
        s.push(-1);

        for (int i = n - 1; i >= 0; i--)
        {
            while (s.top() != -1 && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            next[i] = s.top();
            s.push(i);
        }
    }

    void previousSmallerElement(vector<int> &prev, vector<int> heights, int n)
    {
        stack<int> s;
        s.push(-1);

        for (int i = 0; i < n; i++)
        {
            while (s.top() != -1 && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            prev[i] = s.top();
            s.push(i);
        }
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> next(n);
        nextSmallerElement(next, heights, n);
        vector<int> prev(n);
        previousSmallerElement(prev, heights, n);

        int ans = 0, l, w, newArea;

        for (int i = 0; i < n; i++)
        {
            l = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }

            w = next[i] - prev[i] - 1;

            newArea = l * w;
            ans = max(ans, newArea);
        }

        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        //get the dimensions of the matrix
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        //create another matrix with integer since on leetcode char was given. but no need if argument is in integer
        vector<vector<int>> mat(n);
        //copy the matrix to its integer form
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '0')
                {
                    mat[i].push_back(0);
                }
                else
                {
                    mat[i].push_back(1);
                }
            }
        }
    //create the new histogram matrix
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] != 0)
                {
                    mat[i][j] += mat[i - 1][j];
                }
            }
        }

    //calculate the max area for each row and store
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, largestRectangleArea(mat[i]));
        }

        return ans;
    }
};

int main()
{

    return 0;
}