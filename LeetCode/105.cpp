#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
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

class Solution {
public:

    void preOrder(TreeNode*  root)
    {
        if(!root)return;

        cout<<root->val<<endl;

        preOrder(root->left);
        preOrder(root->right);
         
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    }
};




int main(void)
{
    


    return 0;
}