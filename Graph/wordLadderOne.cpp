#include <bits/stdc++.h>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    // set banake sare words dal diye
    unordered_set<string> s;
    for (int i = 0; i < wordList.size(); i++)
    {
        if (wordList[i] != beginWord)
            s.insert(wordList[i]);
    }
    // queue banake pehla word dal diya aur set se nikal diya agar hoga
    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while (!q.empty())
    {
        string curr = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (curr == endWord)
            return dist;

        for (int j = 0; j < curr.size(); j++)
        {
            char ori = curr[j];
            for (int i = 0; i < 26; i++)
            {
                curr[j] = 'a' + i;

                if (s.find(curr) != s.end())
                {
                    q.push({curr, dist + 1});
                    s.erase(curr);
                }
                curr[j]=ori;
            }
        }
    }

    return 0;
}
int main()
{
    return 0;
}