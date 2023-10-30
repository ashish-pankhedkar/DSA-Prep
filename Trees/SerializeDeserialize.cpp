#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    string ans = "";
    if (root == NULL)
        return ans;

    queue<TreeNode *> q;
    q.push(root);
    //here for loop is not used as in level order since
    //we just want to traverse all the nodes irrespective of them being null and
    //not get them orderwise
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        //if the node is not null then append it to string and push its children to queue
        if (temp != NULL)
        {
            ans.append(to_string(temp->val) + ",");
            q.push(temp->left);
            q.push(temp->right);
        }
        else
        {
            ans.append("#,");
        }
    }
    return ans;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return NULL;

    //string stream makes the string into an input stream
    stringstream s(data);
    string str;

    //get line gets yout the string till first occurence of the delimiter
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
        {
            temp->left = NULL;
        }
        else
        {
            TreeNode *leftNode = new TreeNode(stoi(str));
            temp->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if (str == "#")
        {
            temp->right = NULL;
        }
        else
        {
            TreeNode *rightNode = new TreeNode(stoi(str));
            temp->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

int main()
{
    return 0;
}