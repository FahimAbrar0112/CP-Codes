#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

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
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int left, int right)
    {
        if (left > right)
            return nullptr;
        
        int rootVal = preorder[preorderIndex++];

        TreeNode *root = new TreeNode(rootVal);
        int inorderIndex = inorderMap[rootVal];

        root->left = build(preorder, inorder, left, inorderIndex - 1);

        root->right = build(preorder, inorder, inorderIndex + 1, right);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};

int main(void)
{

    return 0;
}