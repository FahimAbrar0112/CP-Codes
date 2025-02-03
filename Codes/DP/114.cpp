#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

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
    TreeNode *dfs(TreeNode *root)
    {
        if (!root)
            return nullptr;

        TreeNode *leftTail = dfs(root->left);
        TreeNode *rightTail = dfs(root->right);

        if (root->left)
        {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        return rightTail ? rightTail : (leftTail ? leftTail : root);
    }
    void flatten(TreeNode *root)
    {
        dfs(root);
    }
};

int main(void)
{

    return 0;
}