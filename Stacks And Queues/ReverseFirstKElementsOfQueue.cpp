#include <bits/stdc++.h>
using namespace std;
//reverse first k elements
queue<int> rev(queue<int> q, int k)
{
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return q;
}
queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.
    q = rev(q, k);
    int size = q.size();
    // push first n-k eolemensts into the back
    for (int i = 0; i < size - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}
int main()
{
    return 0;
}