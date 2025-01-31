#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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

private:
    void reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;

        while (current)
        {
            ListNode *nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy;

        for (int i = 1; i < left; i++)
        {
            pre = pre->next;
        }

        ListNode *start = pre->next;
        ListNode *end = start;

        for (int i = 1; i <= right - left; i++)
        {
            end = end->next;
        }

        ListNode *post = end->next;

        pre->next = nullptr;
        end->next = nullptr;

        reverse(start);

        pre->next=end;
        start->next=post;

        return dummy->next;
    }
};
