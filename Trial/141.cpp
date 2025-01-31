#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Using set:

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return 0;
        unordered_set<ListNode *> st;

        ListNode *curr = head;
        st.insert(curr);
        curr = curr->next;

        while (curr)
        {
            if (st.count(curr))
                return 1;
            else
            {
                st.insert(curr);
                curr = curr->next;
            }
        }
        return 0;
    }
};

// Hare and Tortoise:

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return 1;
        }

        return 0;
    }
};
