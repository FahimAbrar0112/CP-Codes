#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        // Step 1: Create a map to store the mapping of original nodes to copied nodes
        unordered_map<Node *, Node *> nodeMap;

        // Step 2: First pass - Create new nodes and map them to original nodes
        Node *curr = head;
        while (curr)
        {
            nodeMap[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Step 3: Second pass - Set the next and random pointers for the new nodes
        curr = head;
        while (curr)
        {
            if (curr->next)
            {
                nodeMap[curr]->next = nodeMap[curr->next]; // Set next pointer
            }
            if (curr->random)
            {
                nodeMap[curr]->random = nodeMap[curr->random]; // Set random pointer
            }
            curr = curr->next;
        }

        return nodeMap[head]; // Return the head of the copied list
    }
};
