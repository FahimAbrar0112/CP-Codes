// https : // www.youtube.com/watch?v=jSto0O4AJbM

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        string ans = "";
        if (s.empty() || t.empty())
            return ans;

        unordered_map<char, int> need, have;

        int required = 0;
        int formed = 0;
        int minLen = INT_MAX;
        int ansL = 0, ansR = 0;

        for (auto ch : t)
        {
            if (need[ch] == 0)
                required++;

            need[ch]++;
        }

        int left = 0, right = 0;
        while (right < s.size())
        {
            char ch = s[right];
            have[ch]++;

            if ((need.find(ch) != need.end()) && (need[ch] == have[ch]))
            {
                formed++;
            }

            while (formed == required)
            {

                if (right - left + 1 < minLen)
                {
                    ansL = left;
                    ansR = right;
                    minLen = right - left + 1;
                }

                char toRemoveFromLeft = s[left];
                have[toRemoveFromLeft]--;

                if ((need.find(toRemoveFromLeft) != need.end()) && (have[toRemoveFromLeft]<need[toRemoveFromLeft]))
                {
                    formed--;
                }
                left++;
            }
            right++;
        }
        return minLen==INT_MAX? ans : s.substr(ansL,minLen);
    }
};

int main(void)
{
}