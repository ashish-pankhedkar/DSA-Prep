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
//Striver approach
void righSideView_RecursiveApproach_Helper(TreeNode *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (level > ans.size())
    {
        ans.push_back(root->val);
    }
    righSideView_RecursiveApproach_Helper(root->right, level + 1, ans);
    righSideView_RecursiveApproach_Helper(root->left, level + 1, ans);
}
vector<int> rightSideView_RecursiveAprroach(TreeNode *root)
{
    vector<int> ans;
    righSideView_RecursiveApproach_Helper(root, 1, ans);
    return ans;
}

//Normal approach
vector<int> rightSideView_LevelOrderApproach(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        vector<int> col;
        for (int i = 0; i < s; i++)
        {
            auto temp = q.front();
            q.pop();
            col.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        ans.push_back(col[col.size() - 1]);
    }
    return ans;
}
int main()
{
    return 0;
}