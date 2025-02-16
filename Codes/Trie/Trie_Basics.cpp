#include <bits/stdc++.h>
using namespace std;

/*
    Applications:
    - Autocomplete
    - Spell checking
    - IP routing
    - Dictionary word lookups
    - DNA sequence storage
*/

struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {} // Constructor
};

class Trie
{
private:
    TrieNode *root;

    // Recursive function to delete all nodes in the Trie
    void deleteTrie(TrieNode *node)
    {
        for (auto &pair : node->children)
        {
            deleteTrie(pair.second);
        }
        delete node;
    }

public:
    Trie()
    {
        root = new TrieNode();
    }

    ~Trie()
    {
        deleteTrie(root); // Destructor to free memory
    }

    // Insert a word into the Trie
    void insert(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    // Check if there is any word that starts with a given prefix
    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char c : prefix)
        {
            if (node->children.find(c) == node->children.end())
            {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("car");
    trie.insert("cat");
    trie.insert("bat");

    cout << "Search 'cat': " << trie.search("cat") << endl;   // Output: 1 (true)
    cout << "Search 'bat': " << trie.search("bat") << endl;   // Output: 1 (true)
    cout << "Search 'bar': " << trie.search("bar") << endl;   // Output: 0 (false)
    cout << "Prefix 'ca': " << trie.startsWith("ca") << endl; // Output: 1 (true)

    return 0;
}
