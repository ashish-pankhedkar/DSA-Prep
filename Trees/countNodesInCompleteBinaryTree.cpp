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

//get the left most height
int heightleft(TreeNode *root)
{
    int h = 0;
    while (root)
    {
        h++;
        root = root->left;
    }
    return h;
}

//get the right most height
int heightright(TreeNode *root)
{
    int h = 0;
    while (root)
    {
        h++;
        root = root->right;
    }
    return h;
}

int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = heightleft(root);
    int rh = heightright(root);

// if the left most height and right most height is equal then it means that the tree is full
//since complete tree are filled from left most

    if (lh == rh)
        return pow(2, lh) - 1;

    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}
int main()
{
    return 0;
}