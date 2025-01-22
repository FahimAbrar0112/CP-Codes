#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {

        vector<string> ans;

        int n = words.size();
        int index = 0;

        while (index < n)
        {
            int count = words[index].length();
            int last = index + 1;
            while (last < n)
            {
                if (count + 1 + words[last].length() > maxWidth)
                    break;
                count += 1 + words[last].length();
                last++;
            }

            string tmp;
            int diff = last - 1 - index;

            tmp += words[index];

            if (last == n || diff == 0) // last line
            {
                for (int i = index + 1; i < last; i++)
                {
                    tmp += " ";
                    tmp += words[i];
                }

                int blankSpaces = maxWidth - tmp.length();
                for (int i = 0; i < blankSpaces; i++)
                {
                    tmp += " ";
                }
            }

            else // onno jekono line hoile space gula evenly vag kora lagbe:
            {
                int spaces = (maxWidth - count) / diff;
                int extraSpaces = (maxWidth - count) % diff;
                for (int i = index + 1; i < last; i++)
                {
                    for (int s = spaces; s > 0; s--)
                    {
                        tmp += " ";
                    }
                    if (extraSpaces > 0)
                    {
                        tmp += " ";
                        extraSpaces--;
                    }
                    tmp += " ";  // protttekta word er por must akta space j deyai lagbe oita
                    tmp += words[i];
                }
            }
            ans.push_back(tmp);
            index = last;
        }
        return ans;
    }
};

int main(void)
{
}