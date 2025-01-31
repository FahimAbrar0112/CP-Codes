#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRepeat(unordered_map<char, int>& mp)
    {
        int mx=0;
        for(auto val:mp)
        {
            mx = max(mx,val.second);
        }
        return mx;

    }
    int characterReplacement(string s, int k)
    {

        unordered_map<char,int> count;
        int maxLen = 0;

        int left=0,right=0;
        while (right<s.length())
        {
            char ch = s[right];
            count[ch]++;

            int needReplacement = right-left+1 - maxRepeat(count);
            if(needReplacement<=k)
             maxLen = max(maxLen,right-left+1);
            else
            {
                count[s[left]]--;
                left++;
                
            } 
            right++;




        }
        
    return maxLen;

    }
};


int main(void)
{   
    



}