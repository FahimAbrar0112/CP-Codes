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

class Solution1
{
public:
    int numberOfEdges = 0;
    int height(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        return left + right + (root->left ? 1 : 0) + (root->right ? 1 : 0);
    }
};

class Solution2
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0; // Base case: empty tree has 0 nodes
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int countEdges(TreeNode *root)
    {
        int totalNodes = countNodes(root);
        return (totalNodes > 0) ? totalNodes - 1 : 0; // Edges = Nodes - 1
    }
};
int main()
{
    // Example BST
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(9);
    Solution1 s1;
    cout << "Total Edges in BST: " << s1.height(root) << endl;

    Solution2 s2;
    cout << "Total Edges in BST: " << s2.countEdges(root) << endl;

    return 0;
}