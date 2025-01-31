#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {

        int n = s.size();
        int count = 0;
        bool track = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                track = 1;
                count++;
            }
            else
            {
                if (track)
                    break;
            }
        }
        return count;
    }
};
int main(void)
{
}