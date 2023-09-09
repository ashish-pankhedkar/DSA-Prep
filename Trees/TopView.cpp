#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int lvl = q.front().second;
        Node *frontNode = q.front().first;
        q.pop();

        if (m.find(lvl) == m.end())
        {
            m[lvl] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, lvl - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, lvl + 1));
        }
    }

    for (auto i : m)
    {
        ans.push_back(i.second);
    }

    return ans;
}
int main()
{
    return 0;
}