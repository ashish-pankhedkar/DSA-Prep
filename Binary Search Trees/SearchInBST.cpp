#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *searchBST(TreeNode *root, int val)
{
    while (root != NULL && root->val != val)
    {
        if (val > root->val)
            root = root->right;
        else
            root = root->left;
    }
    return root;
}
int main()
{
    return 0;
}