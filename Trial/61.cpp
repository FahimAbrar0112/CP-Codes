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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;

        int n = 1;
        ListNode *current = head;
        ListNode *tail = current;

        while (current->next)
        {
            n++;
            current = current->next;
        }

        tail = current;
        k %= n;
        if (k == 0)
            return head;

        int ct = n - k;
        current = head;

        while (--ct)
        {
            current = current->next;
        }

        ListNode *start = current->next;
        ListNode *end = tail;
        
        current->next = nullptr;
        end->next = head;
        head = start;

        return head;
    }
};
