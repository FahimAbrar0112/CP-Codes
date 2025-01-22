#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int maxWindLen = 0;
        int left = 0;
        unordered_set<char> window;

        for (int right = 0; right < s.size(); right++)
        {
            while (window.find(s[right]) != window.end())
            {
                window.erase(s[left]);
                left++;
            }
            int currectWindowLen = right - left + 1;
            maxWindLen = max(maxWindLen, currectWindowLen);
            window.insert(s[right]);
        }

        return maxWindLen;
    }
};
