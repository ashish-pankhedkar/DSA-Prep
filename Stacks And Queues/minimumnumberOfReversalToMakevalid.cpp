//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int countRev(string s);
int main()
{

    string s;
    cout << "Enter string with {} brackets : ";
    cin >> s;
    cout << countRev(s) << '\n';
}

// Contributed By: Pranay Bansal
// } Driver Code Ends

int countRev(string str)
{
    // if odd then return -1;
    if (str.length() % 2 == 1)
        return -1;

    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        // if open bracket then piush to stack
        if (c == '{')
            s.push(c);
        else
        { // closed and corresponding open found then pop
            if (s.empty() == 0 && s.top() == '{')
            {
                s.pop();
            }
            // close and no corresponding open then push the closed
            else
            {
                s.push(c);
            }
        }
    }

    int a = 0, b = 0;

    while (!s.empty())
    {
        if (s.top() == '{')
        {
            a++;
        }
        else
            b++;

        s.pop();
    }

    return ((a + 1) / 2) + ((b + 1) / 2);
}