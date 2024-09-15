#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *inOrderSuccessor(Node *root, Node *x)
{
    // Your code here
    Node *next = NULL;
    while (root)
    {
        // this means the given node can be a successor but we need to find something smaller if it exists so move to left and store the current
        if (root->data > x->data)
        {
            next = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return next;
}

Node *inOrderPredecessor(Node *root, Node *x)
{
    // Your code here
    Node *prev = NULL;
    while (root)
    {
        // this means the given node can be a successor but we need to find something smaller if it exists so move to left and store the current
        if (root->data < x->data)
        {
            prev = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return prev;
}

int main()
{
    return 0;
}