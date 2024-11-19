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

    // Delete alternate nodes:
    void deleteAlternateNodes(Node *&head)
    {
        Node *curr = head;

        while (curr != NULL && curr->next != NULL)
        {

            Node *temp = curr->next;
            curr->next = temp->next;
            curr = curr->next;
            delete temp;
        }
    }
};

int main(void)
{
    linkedList ll;

    ll.insertAtHead(ll.head, 10);
    ll.display(ll.head);
    ll.insertAtHead(ll.head, 20);
    ll.display(ll.head);
    ll.insertAtHead(ll.head, 30);
    ll.display(ll.head);

    ll.insertAtTail(ll.head, 40);
    ll.display(ll.head);
    ll.insertAtTail(ll.head, 50);
    ll.display(ll.head);

    ll.insertAtPosition(ll.head, 69, 3);
    ll.display(ll.head);

    ll.updateKthPosition(ll.head, -500, 3);
    ll.display(ll.head);

    // ll.deleteKthPosition(ll.head, 3);
    // ll.display(ll.head);
    // ll.deleteKthPosition(ll.head, 5);
    // ll.display(ll.head);

    // ll.deleteAtTail(ll.head);
    // ll.display(ll.head);

    ll.deleteAlternateNodes(ll.head);
    ll.display(ll.head);
}