#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};

int findCeil(Node *root, int input)
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