#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;

vector<vector<int>> generate(vector<int>&nums)
{
    int n= nums.size();
    int subset_size=(1<<n);
    vector<vector<int>>subsets;
    for(int mask=0;mask<subset_size;mask++)
    {
        vector<int>subset;
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
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    auto subsets = generate(nums);

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