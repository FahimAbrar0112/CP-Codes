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

class Solution
{
public:
    bool ans = 1; // BST

    bool dfs(TreeNode *root, long long minValue = LONG_MIN,long long maxValue = LONG_MAX) 
    {
        if(!root) return 1;

        if(root->val >= maxValue)
         return 0;
        if(root->val <= minValue)
        return 0;

        return  dfs(root->left,minValue,root->val) && dfs(root->right,root->val,maxValue);
        
    }

    bool isValidBST(TreeNode *root)
    {
        return dfs(root);
    }
};