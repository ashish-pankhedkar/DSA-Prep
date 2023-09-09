#include <bits/stdc++.h>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void changeTree(BinaryTreeNode *root)
{
    // Write your code here.
    if (root == NULL)
        return;

    //get left and right values
    int left = (root->left == NULL ? 0 : root->left->data);
    int right = (root->right == NULL ? 0 : root->right->data);

    //check if the lefta and right  sum is less than the current node
    if (root->data > left + right)
    {   
        //if the sum is less then set the children to the value of current node
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }

    //recurse to the left and right part
    changeTree(root->left);
    changeTree(root->right);

    //get left right part
    left = (root->left == NULL ? 0 : root->left->data);
    right = (root->right == NULL ? 0 : root->right->data);

    //change the root value to sum of children only if it is not leaf else leaf will become 0
    if (root->left != NULL || root->right != NULL)
        root->data = left + right;
}
int main()
{
    return 0;
}