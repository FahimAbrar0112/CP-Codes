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
    int max_path_sum = INT_MIN;

    int height(TreeNode *root)
    {
        if (!root)
            return 0;

        int rVal = root->val;
        int left = max(0, height(root->left));
        int right = max(0, height(root->right));

        max_path_sum = max(max_path_sum, rVal + left + right);

        return max(left, right) + rVal;
    }

    int maxPathSum(TreeNode *root)
    {
        height(root);
        return max_path_sum;
    }
};
