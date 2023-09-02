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

//-------Optimized approach---------------
int maxDepth(TreeNode *root, int &maxi)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int lh = maxDepth(root->left, maxi);
        int rh = maxDepth(root->right, maxi);

        maxi = max(maxi, lh + rh);
        return 1 + max(lh, rh);
    }
}

int diameterOfBinaryTree(TreeNode *root)
{
    int maxi = INT_MIN;
    maxDepth(root, maxi);
    return maxi;
}


//----------Navive Approach with O(N^2)----------
int maxi = INT_MIN;
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
void DiameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    maxi = max(maxi, lh + rh);
    DiameterOfBinaryTree(root->left);
    DiameterOfBinaryTree(root->right);
}
int diameterOfBinaryTree(TreeNode *root)
{
    DiameterOfBinaryTree(root);
    return maxi;
}

int main()
{
    return 0;
}