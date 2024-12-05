#include <bits/stdc++.h>
using namespace std;

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
    vector<int> v ={5,1,2,3,7,89,5,9,4,100,5};

    show(v);
    sort(v.begin(),v.end());
    show(v);

    auto it = lower_bound(v.begin(),v.end(),5);
    cout<< (*it) <<endl;

      it = lower_bound(v.begin(), v.end(), 6);
    cout << (*it) << endl;

      it = lower_bound(v.begin(), v.end(), 25);
    cout << (*it) << endl;

      it = lower_bound(v.begin(), v.end(), 200);
       if(it==v.end())
           cout << "Not found" << endl
                << endl;
       else
        cout<<(*it)<<endl<<endl;
}