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
    int dfs(TreeNode *root, int sum)
    {
        if (!root)
            return 0;

        sum = sum * 10 + root->val;

        if (!root->left && !root->right)
            return sum;

        return dfs(root->left, sum) + dfs(root->right, sum);
    }

    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }
};

int main(void)
{

    return 0;
}