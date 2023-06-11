#include <bits/stdc++.h>
using namespace std;

void nextSmallerElement(vector<int> &next, vector<int> heights, int n)
{
    stack<int> s;
    s.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() != -1 && heights[s.top()] >= heights[i]) //if stack not empty i.e top is not -1 and top wala element is greater tab tak pop karo
        {
            s.pop();
        }
        next[i] = s.top(); //abhi chota element hai stack par uska index assign krdo
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
int main()
{

    return 0;
}