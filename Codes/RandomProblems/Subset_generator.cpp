#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;

vector<vector<int>> valied;


void Subset_G(vector<int> &v,vector<int>&sub,int i)
{
    if(i==v.size())
    {
        valied.push_back(sub);
        return;
    }
    else
    {
        sub.push_back(v[i]);
        Subset_G(v,sub,i+1);
        sub.pop_back();
        Subset_G(v,sub,i+1);
    }


}
int main(void)
{
    int n;
    cin>>n;
    vector<int>v,sub;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    Subset_G(v,sub,0);

    for(auto val:valied)
    {
        for(auto value:val)
        {
            cout<<value<<" ";
        }
        cout<<endl;
    }
    cout<<valied.size()<<endl;
    

    return 0;
}