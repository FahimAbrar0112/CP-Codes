#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if(numRows==1) return s;
        vector<string> rows(numRows);

        int n=s.size();
        bool flag=1;
        int index=0;

        for(int i=0;i<n;i++)
        {
            if(flag)
            {
                rows[index].push_back(s[i]);
                index++;
                if(index==numRows)
                {

                 flag=!flag;
                 index-=2;
                }
            }
            else
            {
                rows[index].push_back(s[i]);
                index--;
                if (index == -1)
                    {
                        flag = !flag;
                        index+=2;

                    }
            }
              
        }

        string ans;
        for(int i=0;i<numRows;i++)
        {
            ans+=rows[i];
        }

        return ans;
    }
};

int main(void)
{   
    



}