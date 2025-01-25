#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> words;
        string word;

        // Split the string manually based on spaces
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (!word.empty())   // no empty string is push in words
                {
                    words.push_back(word);
                    word.clear();
                }
            }
            else
            {
                word += s[i];
            }
        }
        if (!word.empty())
            words.push_back(word); // Add the last word

        // If pattern size doesn't match number of words, return false
        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> patternToWord;
        unordered_map<string, char> wordToPattern;

        for (int i = 0; i < pattern.size(); i++)
        {
            char p = pattern[i];
            string w = words[i];

            // Check if pattern char is already mapped to a different word
            if (patternToWord.count(p) && patternToWord[p] != w)
                return false;

            // Check if word is already mapped to a different pattern char
            if (wordToPattern.count(w) && wordToPattern[w] != p)
                return false;

            // Establish the mapping
            patternToWord[p] = w;
            wordToPattern[w] = p;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    string pattern = "abba";
    string s = "dog cat cat dog";

    if (sol.wordPattern(pattern, s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
