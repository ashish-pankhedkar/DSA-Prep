#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> morrisTraversal(TreeNode *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    TreeNode *curr = root;
    //As this will be threaded tree, curr will only be null at last
    while (curr)
    {   
        //First Case: curr ka left NULL hai means left me kuch nahi and curr is root
        //and uska time agaya hai print hone ka, so print and move to right
        if (curr->left == NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        //Else move to left but with modification
        else
        {   //Take dummy node to traverse to right most part of left sub tree
            TreeNode *rightmost = curr->left;
            //move to right till either null (not threaded) or curr(threaded)
            while (rightmost->right && rightmost->right != curr)
            {
                rightmost = rightmost->right;
            }
            //if null then thread the tree to curr and move to left
            if (rightmost->right == NULL)
            {
                rightmost->right = curr;
                curr = curr->left;
            }
            //else threaded, remove the thread print as it is root and then move to right
            else
            {
                rightmost->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return ans;
}