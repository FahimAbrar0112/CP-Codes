
#include <bits/stdc++.h>
using namespace std;


// O( n*n )
class Solution
{
public:
    string hashFunc(string s)
    {

        vector<int> count(26, 0);

        for (char ch : s)
        {

            count[ch - 'a']++;
        }

        string key;
        for (int val : count)
        {
            key += to_string(val) + "###";
        }

        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagramGroups;

        for (string s : strs)
        {

            string key = hashFunc(s);

            anagramGroups[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &group : anagramGroups)
        {
            result.push_back(group.second);
        }

        return result;
    }
};

// Alternative:  O(n*n*log n)

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagramGroups;

        for (string s : strs)
        {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end()); // Sort the string to get its anagram key
            anagramGroups[sortedStr].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &group : anagramGroups)
        {
            result.push_back(group.second);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = sol.groupAnagrams(strs);

    for (auto group : result)
    {
        for (auto word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    cout<<endl;

    return 0;
}
