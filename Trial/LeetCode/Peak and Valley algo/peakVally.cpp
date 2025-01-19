#include <bits/stdc++.h>
using namespace std;

// P V P V P V
// V P V P V P

void peakAndValley(vector<int> &v)
{
    sort(v.begin(), v.end());

    for (int i = 1; i < v.size(); i += 2)
    {
        swap(v[i], v[i - 1]);

    }
}

int main(void)
{
    vector<int> v={2,0,3,5,6,9};
    for(auto val:v){
     cout<<val<<"  ";
    }
    cout<<endl;

    peakAndValley(v);

    for (auto val : v)
    {
        cout << val<<"  ";
    }
   
}