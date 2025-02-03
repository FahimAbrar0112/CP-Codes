#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

//* Definition for a binary tree node.
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
    bool dfs(TreeNode *root, int targetSum, int currentSum)
    {
        if (!root)
            return 0;

        currentSum += root->val;

        if (!root->left && !root->right)
            return targetSum == currentSum;

        bool ans;
        if (root->left)
            ans = dfs(root->left, targetSum, currentSum);
        if (root->right)
            ans |= dfs(root->right, targetSum, currentSum);
        return ans;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return dfs(root, targetSum, 0);
    }
};

int main(void)
{

    return 0;
}