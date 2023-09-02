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
vector<vector<int>> getTreeTraversal(TreeNode *root)
{

    vector<int> inOrder;
    vector<int> preOrder;
    vector<int> postOrder;

    stack<pair<TreeNode *, int>> s;
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    s.push({root, 1});

    while (!s.empty())
    {
        auto it = s.top();
        s.pop();
        // Preorder Rule
        if (it.second == 1)
        {
            preOrder.push_back(it.first->val);
            s.push({it.first, 2});
            if (it.first->left != NULL)
            {
                s.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            inOrder.push_back(it.first->val);
            s.push({it.first, 3});
            if (it.first->right != NULL)
            {
                s.push({it.first->right, 1});
            }
        }
        else
        {
            postOrder.push_back(it.first->val);
        }
    }
    ans.push_back(inOrder);
    ans.push_back(preOrder);
    ans.push_back(postOrder);

    return ans;
}
int main()
{
    return 0;
}