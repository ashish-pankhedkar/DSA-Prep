#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flatten_Iterative(TreeNode *root)
{
    stack<TreeNode *> s;
    if (root == NULL)
        return;

    s.push(root);

    while (!s.empty())
    {
        TreeNode *curr = s.top();
        s.pop();
        // push right first then left so that left is on top and will be first while accessing
        if (curr->right)
            s.push(curr->right);

        if (curr->left)
            s.push(curr->left);

        if (!s.empty())
            curr->right = s.top();

        curr->left = NULL;
    }
}

TreeNode *prev = NULL;
void flatten_Recursive(TreeNode *root)
{
    if (root == NULL)
        return;

    flatten_Recursive(root->right);
    flatten_Recursive(root->left);
    root->right = ::prev;
    root->left = NULL;
    ::prev = root;
}
int main()
{
    return 0;
}