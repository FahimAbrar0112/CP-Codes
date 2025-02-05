#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// WIthout backtracking
class Solution
{
public:
    bool dfs(TreeNode *root, int &target, vector<TreeNode *> &path)
    {

        if (!root)
            return 0;
        if (root->val == target)
        {
            path.push_back(root);
            return 1;
        }

        if (dfs(root->left, target, path) || dfs(root->right, target, path))
        {
            path.push_back(root);
            return 1;
        }

        return 0;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return root;

        vector<TreeNode *> path_x, path_y;
        dfs(root, p->val, path_x);
        dfs(root, q->val, path_y);

        reverse(path_x.begin(), path_x.end());
        reverse(path_y.begin(), path_y.end());

        int size = min(path_x.size(), path_y.size());
        TreeNode *ans;
        for (int i = 0; i < size; i++)
        {
            if (path_x[i] == path_y[i])
            {
                ans = path_x[i];
            }
            else
                break;
        }

        return ans;
    }
};


// Backtracking:
class Solution
{
public:
    bool dfs(TreeNode *root, int &target, vector<TreeNode *> &path)
    {

        if (!root)
            return 0;

        path.push_back(root);

        if (root->val == target)
            return 1;

        if (dfs(root->left, target, path) || dfs(root->right, target, path))
            return 1;

        path.pop_back();    

        return 0;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return root;

        vector<TreeNode *> path_x, path_y;
        dfs(root, p->val, path_x);
        dfs(root, q->val, path_y);

       

        int size = min(path_x.size(), path_y.size());
        TreeNode *ans;
        for (int i = 0; i < size; i++)
        {
            if (path_x[i] == path_y[i])
            {
                ans = path_x[i];
            }
            else
                break;
        }

        return ans;
    }
};
