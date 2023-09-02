#include <bits/stdc++.h>
using namespace std;



//my approach
string FirstNonRepeating(string A)
{
    // Code here

    queue<char> q;
    string s = "";
    int arr[26];

    for (int i = 0; i < 26; i++)
        arr[i] = 0;

    q.push(A[0]);
    s += A[0];
    arr[A[0] - 'a'] = 1;
    for (int i = 1; i < A.size(); i++)
    {
        if (arr[A[i] - 'a'] == 0)
        {
            q.push(A[i]);
        }

        arr[A[i] - 'a']++;

        while (!q.empty() && arr[q.front() - 'a'] > 1)
        {
            q.pop();
        }

        if (q.empty())
        {
            s += '#';
        }
        else
        {
            s += q.front();
        }
    }
    return s;
}

int main()
{
    return 0;
}