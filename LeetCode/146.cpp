#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache
{
private:
    unordered_map<int, Node *> mp;

    Node *head;
    Node *tail;
    int capacity;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        head->prev = nullptr;

        tail->prev = head;
        tail->next = nullptr;
    }

    int get(int key)
    {
        if (mp.count(key))
        {
            Node *node = mp[key];
            int key = node->key;
            int value = node->val;

            remove(node);
            addTOhead(new Node(key, value));

            return value;
        }

        return -1;
    }

    void put(int key, int value)
    {
        // Remove:
        if (mp.count(key))
        {
            remove(mp[key]);
        }

        // overFlow control:
        if (mp.size() == capacity)
        {
            remove(tail->prev);
        }

        // Insert Node:
        addTOhead(new Node(key, value));
    }

    void addTOhead(Node *node)
    {

        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;

        mp[node->key] = node;
    }

    void remove(Node *node)
    {
        mp.erase(node->key);

        node->prev->next = node->next;
        node->next->prev = node->prev;

        delete node;
    }
};

 
