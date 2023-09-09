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
 // Funstion takes preorder inorder, start of both of them and hashmap
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int pS, int pE, int iS, int iE, unordered_map<int, int> &hasher)
{
    //if  start are greater then it implies no node and hence NULL
    if (pS > pE || iS > iE)
        return NULL;

    //First Node of preorder is the root
    TreeNode *root = new TreeNode(preorder[pS]);
    //get the index of root val in inorder
    int iRoot = hasher[root->val];
    // get the nums for the left side that of preorder that is left sub tree
    int numsLeft = iRoot - iS;
    //built left tree 
    //preorder start is incremented by 1
    ///pre order end will be ps+numsleft 
    //inorder start will be iS only
    //inorder end will be root index-1
    root->left = buildTree(preorder, inorder, pS + 1, pS + numsLeft, iS, iRoot - 1, hasher);

    //built right tree 
    //preorder start is incremented by 1
    ///pre order end will be ps+numsleft+1 that is all preorder except left subtree and root
    //inorder start will be root index+1 only
    //inorder end will be root iE
    root->right = buildTree(preorder, inorder, pS + 1 + numsLeft, pE, iRoot + 1, iE, hasher);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{   //create a map to store indices of all the elements in inorer
    unordered_map<int, int> hasher;

    for (int i = 0; i < inorder.size(); i++)
    {
        hasher[inorder[i]] = i;
    }

    TreeNode *root = buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, hasher);
    return root;
}
int main()
{
    return 0;
}