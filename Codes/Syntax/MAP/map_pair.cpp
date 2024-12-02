#include <bits/stdc++.h>
using namespace std;

int main(void)
{   

    // uses comparison:
    map<pair<string, int>, string> mp;

    mp[{"BCD", 10}] = "Fuad";
    mp[{"BCD", 5}] = "GG";

    mp[{"ABC", 1}] = "RR";
    mp[{"ACB", 12}] = "QW";

    for (auto &pair : mp)
    {
        auto &first = pair.first;
        auto &second = pair.second;

        cout << "KEY: " << first.first << " " << first.second << " val: " << second
             << endl;
    }

    cout << mp.size() << endl;
    auto it = mp.find({"BCD", 5});

    mp.erase(it);
    cout << endl
         << endl;
    for (auto &pair : mp)
    {
        auto &first = pair.first;
        auto &second = pair.second;

        cout << "KEY: " << first.first << " " << first.second << " val: " << second
             << endl;
    }

    cout << mp.size() << endl;

    mp.clear();
    cout << endl
         << endl;
    for (auto &pair : mp)
    {
        auto &first = pair.first;
        auto &second = pair.second;

        cout << "KEY: " << first.first << " " << first.second << " val: " << second
             << endl;
    }
    cout<<mp.size()<<endl;
}