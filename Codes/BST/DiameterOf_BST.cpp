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
    int maxDiameter = 0;
    int height(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = height(root->left);
        int right = height(root->right);
        maxDiameter = max(maxDiameter, left + right);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        return height(root);
    }
};
int main(void)
{

    return 0;
}