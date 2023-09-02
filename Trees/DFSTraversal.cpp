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

// --------------------RECURSIVE APPROACH -------------------------------------
void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

void preorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

void postorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

//-----------------------------------ITERATIVE APPROACH--------------------------
vector<int> preorder_I(TreeNode *root)
{
    stack<TreeNode *> s;
    vector<int> ans;
    s.push(root);

    while (!s.empty())
    {
        TreeNode *temp = s.top();
        s.pop();
        ans.push_back(temp->val);
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
}

vector<int> inOrder(TreeNode *root)
{
    // Your code here
    vector<int> result;
    stack<TreeNode *> s;

    TreeNode *node = root;
    while (true)
    {
        if (node != NULL)
        {
            s.push(node);
            node = node->left;
        }
        else
        {
            if (s.empty())
                break;
            node = s.top();
            s.pop();
            result.push_back(node->val);
            node = node->right;
        }
    }

    return result;
}

vector<int> postorder_I(TreeNode *root)
{
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;
    vector<int> ans;
    s1.push(root);

    while (!s1.empty())
    {   
        TreeNode *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }
    while(!s2.empty())
    {
         ans.push_back(s2.top()->val);
         s2.pop();
    }   

    return ans;
}


int main()
{
    return 0;
}