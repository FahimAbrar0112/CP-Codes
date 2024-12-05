#include <bits/stdc++.h>
using namespace std;

void show(map<int,int> &mp)
{
    for(auto pair:mp)
    {
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    cout<<endl;
}

int main(void)
{   
    map<int,int>mp ;
    mp[5]=12;
    mp[12]=11;
    mp[1]=32;
    mp[3]=133;

    show(mp);

    auto it = mp.lower_bound(5);
    cout<< it->first<<" "<<it->second<<endl;

      it = mp.upper_bound(5);
    cout << it->first << " " << it->second << endl;
}