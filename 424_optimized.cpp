#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> count(26, 0);

        int maxFrequency = 0, left = 0, right = 0, maxLen = 0;

        while (right < s.length())
        {
            char ch = s[right];
            count[ch - 'A']++;
            maxFrequency = max(maxFrequency, count[ch - 'A']);

            int needToReplace = right - left + 1 - maxFrequency;

            if (needToReplace > k)
            {
                count[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};



int main(void)
{   
    



}