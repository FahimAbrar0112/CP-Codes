#include <bits/stdc++.h>
using namespace std;

int main(void)
{

    map<int, vector<string>> mp;

    mp[10].push_back("Ab");
    mp[5].push_back("FF");
    mp[12].push_back("Bac");
    mp[10].push_back("pp");    
    mp[10].push_back("GWF");

    for (auto &pair : mp)
    {
        cout << "key: " << pair.first << "  " << " Vals: " ;
        for (auto &val : pair.second)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}