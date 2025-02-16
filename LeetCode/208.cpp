#include <bits/stdc++.h>
using namespace std;

struct Trienode
{
    unordered_map<char, Trienode *> children;
    bool isEndOfWord;

    Trienode() : isEndOfWord(0)
    {
    }
};

class Trie
{
private:
    Trienode *root;

public:
    Trie()
    {
        root = new Trienode();
    }

    void insert(string word)
    {
        Trienode *node = root;

        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                node->children[c] = new Trienode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = 1;
    }

    bool search(string word)
    {
        Trienode *node = root;

        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                return 0;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    bool startsWith(string prefix)
    {
        Trienode *node = root;

        for (char c : prefix)
        {
            if (node->children.find(c) == node->children.end())
            {
                return 0;
            }
            node = node->children[c];
        }
        return 1;
    }
};
 