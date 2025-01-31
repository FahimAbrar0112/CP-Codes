#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {

        unordered_map<string, int> frequency, curr;

        for (auto word : words)
        {
            frequency[word]++;
        }

        vector<int> ans;
        int n = words.size(); // koyta word ase
        int wordLen = words[0].size();
        int sLen = s.size();
        int winddowSize = n * wordLen;

        for (int startPos = 0; startPos < wordLen; startPos++)
        {

            int start = startPos;
            while (start + winddowSize - 1 < sLen)
            {

                curr = frequency;
                string currWord;
                bool matched= true;  //  matched

                for(int i=0;i<n;i++)
                {
                    currWord = s.substr(start+wordLen*i,wordLen);

                    auto it = curr.find(currWord);
                    if(it==curr.end() || (it->second==0))
                    {
                        matched=false;
                        break;
                    }
                    
                    curr[currWord]--;

                }

                if(matched) ans.push_back(start);
                start+=wordLen;
 
 
            }
        }
       return ans; 
    }
};

int main(void)
{

    vector<string> words = {"abc","xyz"};
    string s = "abcabcxyz";

    Solution S;

    auto ans = S.findSubstring(s,words);

    for(auto val:ans)
    {
        cout<<val<<endl;
    }
}