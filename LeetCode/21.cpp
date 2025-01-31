#include <bits/stdc++.h>
using namespace std;

// * Definition for singly-linked list.
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListNode *head = nullptr, *current = nullptr;

        while (list1 && list2)
        {
            ListNode *newNode = new ListNode();

            if (list1->val <= list2->val)
            {
                newNode->val = list1->val;
                list1 = list1->next;
            }
            else
            {
                newNode->val = list2->val;
                list2 = list2->next;
            }

            if (head == nullptr)
            {
                head = newNode;
                current = head;
            }
            else
            {
                current->next = newNode;
                current = current->next;
            }
        }

        // Attach the remaining nodes from list1 or list2
        if (list1 || list2)
        {
            if (!head)
                head = list1 ? list1 : list2;
            else
                current->next = list1 ? list1 : list2;
        }

        return head;
    }
};
