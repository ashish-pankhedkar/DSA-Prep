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

int findCeil(TreeNode *root, int input)
{
    if (root == NULL)
        return -1;

    // Your code here
    int ceil = -1;
    while (root)
    {
        if (root->data == input)
        {
            ceil = root->data;
            break;
        }
        else if (root->data < input)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}
int main()
{
    return 0;
}