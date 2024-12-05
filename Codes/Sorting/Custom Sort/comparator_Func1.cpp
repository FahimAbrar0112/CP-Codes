#include <bits/stdc++.h>
using namespace std;


bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.first!=b.first)
     return a.first<b.first;
    else
     return a.second>b.second; 
}

void show(vector<pair<int, int>> &v)
{
    for (auto x : v)
    {
        cout << x.first << " "<<x.second<<endl;
    }
    cout << endl;
}

int main(void)
{
    vector<pair<int, int>> v = {
        {10, 5}, {54, 1}, {10, 6}, {10, 4}, {5, 10}, {7, 12}};

        show(v);
        sort(v.begin(),v.end(),cmp);
        show(v);
}