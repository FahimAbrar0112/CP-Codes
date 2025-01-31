#include <bits/stdc++.h>
using namespace std;

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int ct = 0;
        ListNode *curr = head;
        while (curr)
        {
            ct++;
            curr = curr->next;
        }

        if(ct==n)
        {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        ct -= n;

        curr = head;
        while (curr)
        {
            ct--;
            if (ct == 0)
                break;
            curr = curr->next;
        }

        ListNode *toBeDeleted = curr->next;
        curr->next = toBeDeleted->next;
        delete toBeDeleted;

        return head;
    }
};
 