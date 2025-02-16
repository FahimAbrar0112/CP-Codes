#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
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

    // Find the node corresponding to the last character of the prefix
    TrieNode *findNode(string prefix)
    {
        TrieNode *node = root;
        for (char c : prefix)
        {
            if (node->children.find(c) == node->children.end())
            {
                return nullptr; // Prefix not found
            }
            node = node->children[c];
        }
        return node; // Found the node where prefix ends
    }

    // Recursive DFS function to collect all words from a given node
    void dfs(TrieNode *node, string currentWord, vector<string> &words)
    {
        if (node->isEndOfWord)
        {
            words.push_back(currentWord);
        }

        for (auto &pair : node->children)
        {
            dfs(pair.second, currentWord + pair.first, words);
        }
    }

    // Function to get all words with a given prefix
    vector<string> getWordsWithPrefix(string prefix)
    {
        TrieNode *node = findNode(prefix);
        vector<string> words;

        if (!node)
            return words; // If prefix is not in the trie, return empty list

        dfs(node, prefix, words);
        return words;
    }
};

int main()
{
    Trie trie;
    trie.insert("car");
    trie.insert("cat");
    trie.insert("cart");
    trie.insert("bat");
    trie.insert("can");
    trie.insert("cap");

    string prefix = "ca";
    vector<string> words = trie.getWordsWithPrefix(prefix);

    cout << "Words with prefix '" << prefix << "':\n";
    for (string word : words)
    {
        cout << word << endl;
    }

    return 0;
}
