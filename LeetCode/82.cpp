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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        while (head)
        {
            bool duplicatePresent = 0;
            while (head->next && head->val == head->next->val)
            {
                head = head->next;
                duplicatePresent = 1;
            }

            if (duplicatePresent)
            {
                prev->next = head->next;
            }
            else
            {
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy->next;
    }
};

ListNode *createLinkedList(vector<int> values)
{
    if (values.empty())
        return nullptr;

    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;

    for (int i = 1; i < values.size(); i++)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current)
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    vector<int> values = {1, 2, 3, 3, 4, 4, 5};  
    ListNode *head = createLinkedList(values);

    cout << "Original Linked List: ";
    printLinkedList(head);

    Solution solution;
    head = solution.deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printLinkedList(head);

    return 0;
}
