#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool present(TreeNode *root, vector<int> &arr, int x)
{   //if null then return false
    if (root == NULL)
        return false;
    //add the current node to array
    arr.push_back(root->val);

    //if the current node is target then return true
    if (root->val == x)
        return true;

    //if not then check if left and right subtree has the target, if it has then return true
    if (present(root->left, arr, x) || present(root->right, arr, x))
        return true;
    //if not present then remove the current node as path is not through it and return false
    arr.pop_back();
    return false;
}
vector<int> solve(TreeNode *A, int B)
{
    vector<int> ans;
    if (A == NULL)
        return ans;

    present(A, ans, B);
    return ans;
}
int main()
{
    return 0;
}