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
int maxPathSumHelper(TreeNode *root, int &maxi)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = max(0, maxPathSumHelper(root->left, maxi));
    leftSum = leftSum < 0 ? 0 : leftSum;
    int rightSum = max(0, maxPathSumHelper(root->right, maxi));
    maxi = max(maxi, root->val + leftSum + rightSum);
    return (root->val + max(leftSum, rightSum));
}

int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    maxPathSumHelper(root, maxi);
    return maxi;
}
int main()
{
    return 0;
}