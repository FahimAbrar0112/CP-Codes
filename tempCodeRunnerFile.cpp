class Solution
{
public:
    bool dfs(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return 1;
        if (p == nullptr || q == nullptr || (p->val != q->val))
            return 0;

        return dfs(p->left, q->left) && dfs(p->right, q->right);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return dfs(p, q);
    }
};