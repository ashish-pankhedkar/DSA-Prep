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

TreeNode *help(vector<int> &preorder, int &ind, int ub)
{
    if (ind == preorder.size() || preorder[ind] > ub)
        return NULL;

    TreeNode *root = new TreeNode(preorder[ind]);
    ind++;
    root->left = help(preorder, ind, root->val);
    root->right = help(preorder, ind, ub);

    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int ind = 0;
    return help(preorder, ind, INT_MAX);
}
int main()
{
    return 0;
}