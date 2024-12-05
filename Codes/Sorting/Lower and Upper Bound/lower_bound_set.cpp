#include <bits/stdc++.h>
using namespace std;

void show(set<int>&s)
{
    for(auto val:s)
    {
        cout<<val<<" ";
    }
    cout<<endl<<endl;
}

int main(void)
{   
    set<int> s={5,3,1,2,3,5,8,10,12};


    show(s);

    auto it = s.lower_bound(5);

    cout<<*it<<endl;
    

    it =s.upper_bound(5);
    cout<< *it<< endl;


}