#include <bits/stdc++.h>
using namespace std;

class Solution 
{
  public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
       stack<int> st;
       vector<int>nge(nums.size());

        for(int i=0;i<nums.size();i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                while(  nums[i]> nums[st.top()])
                {
                    nge[st.top()] =nums[i];
                    st.pop(); 
                    if(st.empty())
                    break;
                }
                st.push(i);
            }
        }

        while(!st.empty())
        {
            int ind = st.top();
            for(int i=0;i<ind;i++)
            {
                if(nums[i]>nums[ind] )
                {
                    nge[ind] = nums[i];
                    st.pop();
                    break;
                }
            }

            if(ind == st.top())
            {
                nge[st.top()] = -1;
                st.pop();
            }
        }   
        return nge;
    }    
};



int main(void)
{   
    

    vector<int> v = {1,2,3,4,3};
    Solution s;
    auto tmp = s.nextGreaterElements(v);

    for(auto val:tmp)
    {
        cout<<val<<" ";
    }

}