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
    int postIndex;

    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int left, int right)
    {

        if (left > right)
            return nullptr;

        int rootVal  = postorder[postIndex--];

        TreeNode *root =  new TreeNode(rootVal);

        int inorderIndex= inorderMap[rootVal];

        root->right  = build(inorder,postorder,inorderIndex+1,right);

        root->left=build(inorder,postorder,left,inorderIndex-1);

        return root;


    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        postIndex = inorder.size() - 1;

        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, inorder.size() - 1);


    }

};

void printTree(TreeNode* root) {
    if (!root) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();  // Number of nodes at the current level

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;  // New line for each level
    }
}


int main() {
    Solution S;

    // Example tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    vector<int> inorder = {4, 2, 5, 1, 3, 6};
    vector<int> postorder = {4, 5, 2, 6, 3, 1};

    TreeNode* root = S.buildTree(inorder, postorder);

    cout << "Binary Tree (Level-Order Representation):" << endl;
    printTree(root);

    return 0;
}

