#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};

//Add leaves to the result
void leavesTraversal(Node *root, vector<int> &res)
{   //if the node is leaf add it to result and do inorder traversal
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    //move to left sub tress
    if (root->left)
        leavesTraversal(root->left, res);
    //move to right sub tree 
    if (root->right)
        leavesTraversal(root->right, res);
}

void addLeftBoundary(Node *root, vector<int> &res)
{   
    Node *cur = root;
    while (cur)
    {   // if not leaf add to res
        if (!isLeaf(cur))
            res.push_back(cur->data);
        //move leftwards, if not left then righwards
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void addRightBoundary(Node *root, vector<int> &res)
{   //use stack to store elements to reverse
    stack<int> s;
    Node *cur = root;
    while (cur)
    {
        if (!isLeaf(cur))
        {
            s.push(cur->data);
        }
        //move rightwards, if not then leftwards
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    // add the stack elements so that they are reversed
    while (!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }
}
//check if the node is leaf or not
bool isLeaf(Node *root)
{
    return (root->left == NULL) && (root->right == NULL);
}
vector<int> boundary(Node *root)
{
    // Your code here
    vector<int> res;
    if (root == NULL)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root->left, res);
    leavesTraversal(root, res);
    addRightBoundary(root->right, res);

    return res;
}
int main()
{
    return 0;
}
