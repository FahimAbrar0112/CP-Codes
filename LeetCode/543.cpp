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
    int heightOftree(TreeNode *root)
    {
        if (!root)
            return -1;

        int leftHeight = heightOftree(root->left);

        int rightHeight = heightOftree(root->right);

        return max(leftHeight,rightHeight)+1;

    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        
    }
};
int main(void)
{

    return 0;
}