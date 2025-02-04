#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Function to find the depth of a given node
    int findDepth(TreeNode *root, int target, int depth = 0)
    {
        if (!root)
            return -1; // Node not found

        if (root->val == target)
            return depth;

        // Check in left and right subtrees
        int leftDepth = findDepth(root->left, target, depth + 1);
        if (leftDepth != -1)
            return leftDepth;

        int rightDepth = findDepth(root->right, target, depth + 1);
        return rightDepth;
    }
};

int main()
{
    // Example tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;

    // Find depth of node 5
    int target = 5;
    int depth = solution.findDepth(root, target);

    if (depth != -1)
        cout << "Depth of node " << target << " is: " << depth << endl;
    else
        cout << "Node " << target << " not found in the tree." << endl;

    return 0;
}
