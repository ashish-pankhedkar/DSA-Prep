#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        // code here..
        stack<int> ss;
        int stop = (sizeOfStack) / 2;
        for (int i = 0; i < stop; i++)
        {
            ss.push(s.top());
            s.pop();
        }
        s.pop();
        while (!ss.empty())
        {
            s.push(ss.top());
            ss.pop();
        }
        return;
    }

    // /recursive approach
    void solve(stack<int> &s, int sizeOfStack,int count)
    {   
        //basecase
        if(count == sizeOfStack)
        {
            s.pop();
            return;
        }

        int num = s.top();
        s.pop();

        solve(s,sizeOfStack,++count);
        s.push(num);
        return;

    }
    void deleteMidd(stack<int> &s, int sizeOfStack)
    {
        int cnt = 0;
        solve( &s,sizeOfStack, cnt);
        return;
    }

    
};