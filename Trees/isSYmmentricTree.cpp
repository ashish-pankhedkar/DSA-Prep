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
bool isSymmentricHelper(TreeNode *left, TreeNode *right)
{
    if (left == NULL || right == NULL)
        return left == right;

    if (left->val != right->val)
        return false;

    return isSymmentricHelper(left->left, right->right) && isSymmentricHelper(left->right, right->left);
}
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    else
        return isSymmentricHelper(root->left, root->right);
}
int main()
{
    return 0;
}