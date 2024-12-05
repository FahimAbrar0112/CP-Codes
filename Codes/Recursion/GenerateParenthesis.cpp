#include <bits/stdc++.h>
using namespace std;

vector<string> generateParenthesis(int op, int cl, vector<string> &s, string &tmp)
{
    

    if(op==0 && cl==0) 
    {
        s.push_back(tmp);
    }

    if(op!=0)
    {
        tmp.push_back('(');
        op--;
        
    }
}

int main(void)
{   
    

    vector<string>s;


}