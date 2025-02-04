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
    int height(TreeNode *root)
    {
        if (!root)
            return -1; // Base case: empty tree has height -1

        int leftHeight = height(root->left);   // Height of left subtree
        int rightHeight = height(root->right); // Height of right subtree

        return max(leftHeight, rightHeight) + 1; // Height of current tree
    }
};

int main()
{
    // Example tree:
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    cout << "Height of the tree: " << solution.height(root) << endl;
 

    return 0;
}