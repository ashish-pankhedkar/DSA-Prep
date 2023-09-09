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

vector<vector<int>> verticalTraversal(TreeNode *root)
{   //To store Ans
    vector<vector<int>> ans;
    //Queue to store Node and its coordinates
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    //map to track for each vertical what levels are present, for each of that level what values are present
    // Vertical -> Levels -> Set of all values present
    map<int, map<int, multiset<int>>> traversal;

    while (!q.empty())
    {   // Get all rqs values
        TreeNode *temp = q.front().first;
        int vertical = q.front().second.first;
        int level = q.front().second.second;
        q.pop();
        //insert the current node in the map
        traversal[vertical][level].insert(temp->val);
        //insert left and right child
        if (temp->left)
        {
            q.push({temp->left, {vertical - 1, level + 1}});
        }
        if (temp->right)
        {
            q.push({temp->right, {vertical + 1, level + 1}});
        }
    }
    //make required ans from the map : map is in ascending order
    for (auto p : traversal)
    {
        // P is pair of Vertical, <level,set of values>
        vector<int> col;
        for (auto q : p.second)
        {
            //q is pair of level,<set of values>
            for (auto r : q.second)
            {
                //r is each value int he set of values
                col.push_back(r);
            }
        }
        ans.push_back(col);
    }
    return ans;
}
int main()
{
    return 0;
}