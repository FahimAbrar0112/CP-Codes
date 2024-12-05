#include <bits/stdc++.h>
using namespace std;

void generateParenthesis(string &s, int open, int close, vector<string> &valied)
{
    if (open == 0 && close == 0)
    {
        valied.push_back(s);
        return;
    }

    if (open > 0)
    {
        s.push_back('(');
        generateParenthesis(s, open - 1, close, valied);
        s.pop_back();
    }

    if (close > 0 && open < close)
    {
        s.push_back(')');
        generateParenthesis(s, open, close - 1, valied);
        s.pop_back();
    }
}

void print(vector<string> &valied)
{
    cout << valied.size() << endl;
    for (auto v : valied)
    {
        cout << v << "      ";
    }
    cout << endl;
}

int main(void)
{

    vector<string> valied;
    string s;   

    int bracket = 2;

    generateParenthesis(s, bracket, bracket, valied);
    print(valied);
}