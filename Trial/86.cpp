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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *smallDummy = new ListNode(0);
        ListNode *bigDummy = new ListNode(0);

        ListNode *current = head;
        ListNode *small = smallDummy, *big = bigDummy;

        while (current)
        {
            if (current->val < x)
            {
                small->next = current;
                small = small->next;
            }
            else
            {
                big->next = current;
                big = big->next;
            }
            current = current->next;
        }

        big->next = nullptr;
        small->next = bigDummy->next;

        return smallDummy->next;
        ;
    }
};
