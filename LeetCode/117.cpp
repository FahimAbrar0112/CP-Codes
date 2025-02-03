#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();
            Node *dummy = new Node();

            for (int i = 0; i < levelSize; i++)
            {
                Node *node = q.front();
                q.pop();

                dummy->next = node;
                dummy = dummy->next;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return root;
    }
};


class makeTree
{
public:
    // Deserialize the input array to a binary tree (level-order traversal)
    Node *deserialize(const vector<int> &values)
    {
        if (values.empty())
            return nullptr;

        Node *root = new Node(values[0]);
        queue<Node *> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < values.size())
        {
            Node *curr = q.front();
            q.pop();

            if (values[i] != -1)
            {
                curr->left = new Node(values[i]);
                q.push(curr->left);
            }
            i++;

            if (i < values.size() && values[i] != -1)
            {
                curr->right = new Node(values[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }

    // Print the tree with next pointers
    void printTree(Node *root)
    {
        if (!root)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i)
            {
                Node *curr = q.front();
                q.pop();
                cout << curr->val;
                if (curr->next)
                    cout << "->" << curr->next->val;
                else
                    cout << "->#";
                cout << " ";

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            cout << endl;
        }
    }
};



    int main(void)
    {
        // Input: level-order array for the tree
        vector<int> input = {2, 1, 3, 0, 7, 9, 1, 2, -1, 1, 0, -1, -1, 8, 8, -1, -1, -1, -1, 7};

        Solution sol;

        makeTree T;

        // Step 1: Deserialize the input to a binary tree
        Node *root = T.deserialize(input);

        // Step 2: Connect the next pointers
        root = sol.connect(root);

        // Step 3: Print the tree with next pointers
        T.printTree(root);

        return 0;
    }
