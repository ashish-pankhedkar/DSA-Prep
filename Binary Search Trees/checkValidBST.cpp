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
bool helper(TreeNode *root, long low, long high)
{
    if (root == NULL)
        return true;

    if (root->val <= low || root->val >= high)
        return false;

    bool isLBST = helper(root->left, low, root->val);
    bool isRBST = helper(root->right, root->val, high);
    return isLBST && isRBST;
}

bool isValidBST(TreeNode *root)
{

    return helper(root, long(INT_MIN) - 1, long(INT_MAX) + 1);
}
int main()
{
    return 0;
}