#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class linkedList
{
public:
    Node *head;
    linkedList()
    {
        head = NULL;
    }

    // head node er age insert korar jonno: O(1)
    void insertAtHead(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // tail node er pore insert korar jonno: O(N)
    void insertAtTail(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Particular position e insert korar jonno: O(N):
    void insertAtPosition(Node *&head, int data, int pos)
    {
        Node *newNode = new Node(data);
        if (pos == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Update k-th node:
    void updateKthPosition(Node *&head, int data, int pos)
    {
        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->val = data;
    }

    // Delete k-th node:
    void deleteKthPosition(Node *&head, int pos)
    {
        Node *temp = head;
        if (pos == 1)
        {
            head = temp->next;
            delete temp;
            return;
        }

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node *toBeDeleted = temp->next;
        temp->next = temp->next->next;
        delete toBeDeleted;
    }
    // Delete at Tail:
    void deleteAtTail(Node *&head)
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *toBeDeleted = temp->next;
        temp->next = NULL;
        delete toBeDeleted;
    }

    // linked list er element gulo print korar jonno: O(N)

    void display(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // OWN:
    void deleteDuplicateElement1(Node *&head)
    {
        Node *curr = head;
        Node *temp = curr->next;
        while (curr != NULL && temp != NULL)
        {
            if (curr->val == temp->val)
            {
                // cout << " GG: " << temp->val << endl;
                Node *toBeDeleted = temp;
                temp = temp->next;
                delete toBeDeleted;
            }
            else
            {
                // cout << " HH : " << temp->val << endl;
                curr->next = temp;
                curr = curr->next;
                temp = temp->next;
            }
        }
    }

    // Better: O(n)
    void deleteDuplicateElement2(Node *&head)
    {
        Node *curr = head;
        while (curr) //==> while(curr!=NULL)
        {
            while (curr->next && curr->val == curr->next->val)
            {
                Node *toBeDeleted = curr->next;
                curr->next = curr->next->next;
                delete toBeDeleted;
            }
            curr = curr->next;
        }
    }
};

int main(void)
{
    linkedList ll;

    ll.insertAtHead(ll.head, 100);
    ll.display(ll.head);
    ll.insertAtHead(ll.head, 90);
    ll.display(ll.head);
    ll.insertAtHead(ll.head, 80);
    ll.display(ll.head);

    ll.insertAtHead(ll.head, 70);
    ll.display(ll.head);
    ll.insertAtHead(ll.head, 60);
    ll.display(ll.head);
    ll.insertAtHead(ll.head, 50);
    ll.display(ll.head);

    ll.insertAtHead(ll.head, 50);
    ll.insertAtPosition(ll.head, 60, 3);
    ll.display(ll.head);

    ll.insertAtPosition(ll.head, 90, 7);
    ll.insertAtPosition(ll.head, 90, 7);
    ll.display(ll.head);

    // ll.deleteDuplicateElement1(ll.head);
    // ll.display(ll.head);

    ll.deleteDuplicateElement2(ll.head);
    ll.display(ll.head);
}