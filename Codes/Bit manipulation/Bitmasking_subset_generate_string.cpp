#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;

vector<string> generate(string&nums)
{
    int n= nums.size();
    int subset_size=(1<<n);
    vector<string>subsets;
    for(int mask=0;mask<subset_size;mask++)
    {
        string subset;
        for(int i=2;i>=0;i--)
        {
            if(mask & (1<<i)) 
            {
                subset.push_back(nums[i]);
            }
        }
       subsets.push_back(subset); 
    }

   return subsets; 


}

int main(void)
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    auto subsets = generate(s);

    for(auto subset:subsets)
    {
        for(auto val:subset)
        {
            cout<<val<<" ";
        }
       cout<<endl; 
    }


    return 0;
}