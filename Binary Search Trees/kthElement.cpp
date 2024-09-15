#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
void help(TreeNode *root, int &k, int &ans)
{
    if (root == NULL)
        return;
    help(root->left, k, ans);
    k--;
    if (!k)
        ans = root->val; return;
    help(root->right, k, ans);
}
int kthSmallest(TreeNode *root, int k)
{
    // vector<int> ans;
    int cnt = 0, ans = -1;
    help(root, k, ans);
    return ans;
}
int main()
{
    return 0;
}