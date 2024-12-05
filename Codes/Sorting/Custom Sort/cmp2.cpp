#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second > b.second;
}

void show(vector<pair<string, int>> &v)
{
    for (auto x : v)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
}

int main(void)
{
    vector<pair<string, int>> v = {
       {"zzw",3}, {"abc", 5}, {"abc", 1}, {"bac", 6}, {"sfa", 4}, {"bfd", 10}, {"bdw", 12}};

    show(v);
    sort(v.begin(), v.end(), cmp);
    show(v);
}