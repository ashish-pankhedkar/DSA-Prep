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

//---------------Optimized O(n) Approach-------------
int chck(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = chck(root->left);
    int rh = chck(root->right);

    if ((lh != -1) && (rh != -1) && (abs(lh - rh) <= 1))
    {
        return 1 + max(lh, rh);
    }

    else
    {
        return -1;
    }
}

bool isBalancedOptimized(TreeNode *root)
{
    if (chck(root) == -1)
    {

        return false;
    }
    else
        return true;
}

//-------------naive O9N^2) Approach----------------
int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return (1 + max(maxDepth(root->left), maxDepth(root->right)));
    }
}
bool isBalanced(TreeNode *root)
{
    if (root == NULL)
        return true;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    {
        return true;
    }
    else
        return false;
}
int main()
{
    return 0;
}