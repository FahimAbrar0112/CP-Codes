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

int main(void)
{

    Node *head = NULL;
    insertAtHead(head, 10);
    display(head);
    insertAtHead(head, 20);
    display(head);
    insertAtHead(head, 30);
    display(head);

    insertAtTail(head, 40);
    display(head);
    insertAtTail(head, 50);
    display(head);

    insertAtPosition(head, 69, 3);
    display(head);

    updateKthPosition(head, -500, 3);
    display(head);

    //  deleteKthPosition( head, 3);
    //  display( head);
    //  deleteKthPosition( head, 5);
    //  display( head);

    //  deleteAtTail( head);
    //  display( head);

    
}