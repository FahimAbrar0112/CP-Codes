#include <bits/stdc++.h>
using namespace std;


bool cmp(int a,int b)
{
    return a>b;
}







void show(vector<int> &v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main(void)
{

    vector<int> v = {5, 1, 2, 10, 6, 23, 1, 42, 17};
    show((v));
    sort(v.begin(), v.end(),cmp);
    show(v);
}