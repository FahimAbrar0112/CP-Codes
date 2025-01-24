#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";

        int start = 0, maxLen = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            // Odd-length palindrome (center at i)
            expandAroundCenter(s, i, i, start, maxLen);

            // Even-length palindrome (center between i and i+1)
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string &s, int l, int r, int &start, int &maxLen)
    {
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            if (r - l + 1 > maxLen)
            {
                maxLen = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
    }
};

int main()
{
    Solution sol;
    string s = "babad";
    cout << "Longest palindromic substring: " << sol.longestPalindrome(s) << endl;
    return 0;
}
