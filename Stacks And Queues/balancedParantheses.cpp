#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    int i = 0;
    stack<char> st;

    while (s[i] != '\0')
    { // if openeing then push
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        // if closing
        else
        {   //stack not empty and closing
            if (!st.empty())
            {   //if stack not empty and closing and matching then pop
                if ((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{'))
                {

                    st.pop();
                }
                //if stack not empty and closing and not matching
                else
                return false;
            }
            //stack is empty and closing
            else
            {
                return false;
            }
        }

        // cout<<st.top()<<endl;
        i++;
        return st.empty();
    }

    return st.top() == '*';
}
int main()
{

    return 0;
}