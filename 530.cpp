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
    int ans = INT_MAX;
    TreeNode *prevNode = nullptr;

    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);

        if (prevNode)
            ans = min(ans, root->val - prevNode->val);
        prevNode = root;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        inorder(root);
        return ans;
    }
};
