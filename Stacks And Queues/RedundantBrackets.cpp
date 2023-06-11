#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    // Write your code here.

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // if opening or operator then push

        if (c == '(' || c == '+' || c == '-' || c == '*' || c == '/')
        {
            st.push(c);
        }

        else if (c == ')')
        {
            if (st.top() == '(')
                return true;

            while (st.top() != '(')
            {
                st.pop();
            }

            st.pop();
        }
    }

    return false;
}
int main()
{

    return 0;
}