#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    
    vector<int>tmp;

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!= val)
        {
            tmp.push_back(nums[i]);
            
        }

    }

    int ct = tmp.size();

    for(int i=0;i<ct;i++)
    {
        nums[i]=tmp[i];
    }

    return ct;
}

int main(void)
{   
    



}