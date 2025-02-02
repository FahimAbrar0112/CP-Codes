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
    bool dfs(TreeNode *p, TreeNode *q)
    {
        // If both nodes are null, they are symmetric
        if (!p && !q)
            return 1;

        // If one of the nodes is null or their values are different, they are not symmetric
        if (!p || !q || p->val != q->val)
            return 0;

        // Recursively check the left subtree of `p` with the right subtree of `q`
        // and the right subtree of `p` with the left subtree of `q`
        return dfs(p->left, q->right) && dfs(p->right, q->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return 1;
        // Start the DFS from the root's left and right subtrees
        return dfs(root->left, root->right);
    }
};

int main(void)
{

    return 0;
}