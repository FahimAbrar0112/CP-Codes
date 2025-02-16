#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(0)
    {
    }
};

class WordDictionary
{
    TrieNode *root;

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
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
        node->isEndOfWord = 1;
    }

    bool dfs(TrieNode *node, const string &word, int index)
    {
        if(index==word.size()) return node->isEndOfWord;

        char c = word[index];

        if(c=='.')
        {
            for(auto &child:node->children)
            {
                if(dfs(child.second,word,index+1))
                  return 1;
            }
            return 0;
        }
        else
        {
            if(node->children.find(c)==node->children.end())
            {
                 return 0;

            }

            return dfs(node->children[c],word,index+1);
        }


    }



    bool search(string word)
    {

        return dfs(root, word, 0);
    }
};
