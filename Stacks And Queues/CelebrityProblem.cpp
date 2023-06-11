#include <bits/stdc++.h>
using namespace std;

// graph theory solution

int findJudge(int n, vector<vector<int>> trust)
{
    if (trust.size() == 0 && n == 1)
        return 1;
    vector<int> count(n + 1);
    for (auto person : trust)
    {
        // count[person[0]]--; decrements the trust count of the first person in the pair.
        // This is done because if the first person trusts the second person, it means that
        // the first person does not trust themselves.
        count[person[0]]--;
        // count[person[1]]++; increments the trust count of the second person in the pair.
        // This is done because if the first person trusts the second person, it means that
        // the second person is trusted by the first person.
        count[person[1]]++;
    }

    for (int person = 0; person < count.size(); person++)
    {
        // check if there is a person who is trusted by everyone except themselves (n-1 people)
        // and if such person exists it returns the index of that person.
        if (count[person] == n - 1)
            return person;
    }
    return -1;
}

// stack solution

int findJudge(int n, vector<vector<int>> &trust)
{
    vector<vector<int>> knows(n + 1, vector<int>(n + 1, 0));
    for (auto &it : trust)
    {
        knows[it[0]][it[1]] = 1;
    }
    stack<int> s;

    for (int i = 1; i <= n; i++)
    {
        s.push(i);
    }
    int a, b;

    while (s.size() > 1)
    {
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();

        if (knows[a][b] == 1)
        {
            s.push(b);
        }
        else if (knows[b][a] == 1)
        {
            s.push(a);
        }
        else
        {
            continue;
        }
    }
    if (s.empty())
    {
        return -1;
    }
    int c = s.top();
    // check if rows are zero
    for (int i = 1; i <= n; i++)
    {
        if (knows[c][i] == 1)
        {
            return -1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i != c && knows[i][c] == 0)
        {
            return -1;
        }
    }
    return c;
}
int main()
{

    return 0;
}