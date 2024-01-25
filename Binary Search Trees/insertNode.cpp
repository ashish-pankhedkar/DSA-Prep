#include<bits/stdc++.h>
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

TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *curr, *prev;
        curr = root;
        prev = NULL;
        if(root == NULL) return new TreeNode(val);
        while(curr!= NULL) {
            prev = curr;
            if(curr->val > val) curr = curr->left;
            else curr = curr->right;
        }
        if(val < prev->val) {
            prev->left = new TreeNode(val);
        }
        else
        {
            prev->right = new TreeNode(val);
        }
        return root;
    }
int main(){
   return 0;
}