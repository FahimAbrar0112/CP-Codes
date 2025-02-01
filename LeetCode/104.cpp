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

class Solution
{
public:

    int dfs(TreeNode*root)
    {
        if(!root) return 0;

        int depth=1;
        if(root->left)
        depth=max(depth, dfs(root->left)+1);
        if(root->right)
        depth=max(depth, dfs(root->right)+1);

        return depth;
    }

    int maxDepth(TreeNode *root)
    {
        if(!root) return 0;
        
        return dfs(root);



    }
};

