#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{

    vector<int> ans;
    if (root == NULL)
        return ans;
    // create map for tracking parent and set for visited nodes
    unordered_map<TreeNode *, TreeNode *> parent;
    unordered_set<TreeNode *> visited;

    queue<TreeNode *> q;
    q.push(root);
    // do a bfs traversal to add all parents to map
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left)
            {
                parent[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right)
            {
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    // push the target to queue and initialize dist to 0
    q.push(target);
    int dist = 0;
    // run the loop till queue is empty or dist is reached
    while (!q.empty() && k != dist)
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            // mark the node visited
            visited.insert(temp);

            // if nodes left child is present and not visited then add to queue
            if (temp->left)
            {
                if (visited.find(temp->left) == visited.end())
                    q.push(temp->left);
            }

            // if nodes right child is present and not visited then add to queue
            if (temp->right)
            {
                if (visited.find(temp->right) == visited.end())
                    q.push(temp->right);
            }

            // if parent of the current node is present and not visited then add to queue
            if (parent.find(temp) != parent.end())
            {
                if (visited.find(parent[temp]) == visited.end())
                    q.push(parent[temp]);
            }
        }
        // increment distance as one surface is travelled
        dist++;
    }

    // if queue is empty means no node at distance k, return empty vector
    if (q.empty())
        return ans;

    // queue not empty meaning all the nodes at distacne k are in queue now.
    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}

int main()
{
    return 0;
}