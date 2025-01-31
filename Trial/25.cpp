#include <bits/stdc++.h>
using namespace std;

//* Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // Reverses a linked list starting from `head` in-place.
    // Example: 1 → 2 → 3 → null becomes 3 → 2 → 1 → null.
    void reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;

        while (current)
        {
            // Store next node to avoid losing the reference.
            ListNode *nextNode = current->next;
            // Reverse the pointer direction.
            current->next = prev;
            // Move prev and current forward.
            prev = current;
            current = nextNode;
        }
        // At the end, `prev` is the new head of the reversed list.
    }

    // Reverses nodes in groups of `k` in the linked list.
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // Edge cases: no reversal needed.
        if (k == 1 || !head)
            return head;

        // Create a dummy node to simplify handling the head edge case.
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // `pre` tracks the node before the current group.
        // `curr` iterates through the list.
        ListNode *pre = dummy, *curr = head;
        int count = 1; // Counts nodes in the current group.

        while (curr)
        {
            if (count == k)
            {
                // Reset count for the next group.
                count = 1;

                // `start`: first node of the current group.
                // `end`: last node of the current group.
                // `post`: node immediately after the current group.
                ListNode *start = pre->next;
                ListNode *end = curr;
                ListNode *post = end->next;

                // Detach the current group from the main list.
                pre->next = nullptr; // Break before the group.
                end->next = nullptr; // Break after the group.

                // Reverse the detached group.
                reverse(start);

                // Reattach the reversed group to the main list.
                pre->next = end;    // `end` is now the new head of the reversed group.
                start->next = post; // `start` is now the last node of the reversed group.

                // Update `pre` and `curr` for the next iteration.
                pre = start; // `pre` moves to the last node of the reversed group.
                curr = post; // `curr` starts at the next group's first node.
            }
            else
            {
                // Continue traversing until `k` nodes are found.
                count++;
                curr = curr->next;
            }
        }

        // Return the new head (dummy's next skips the dummy node).
        return dummy->next;
    }
};