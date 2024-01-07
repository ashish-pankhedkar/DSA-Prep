#include <bits/stdc++.h>
using namespace std;
int floor(Node *root, int x)
{
    // Code here
    int floor = -1;
    while (root != NULL)
    {
        if (root->data == x)
            return x;
        else if (root->data > x)
        {
            root = root->left;
        }
        else
        {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}
int main()
{
    return 0;
}