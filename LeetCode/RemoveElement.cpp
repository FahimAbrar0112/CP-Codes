#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int count = 0;
        int INF = INT_MAX;
        vector<int>ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                 count++;
                ans.push_back(nums[i]);
                // cout<<nums[i]<<" ";
            }
          
        }
        for(int i=0;i<count;i++)
        {
            ans.push_back(0);
        }
        nums=ans;


        // cout<<endl;
        for(auto  it:ans)
        {
            // cout<<it<<" ";
        }
        return count;
    }
};


int main(void)
{
    vector<int> v = {0, 1, 2, 2, 3, 0, 4, 2};
    Solution s;
    s.removeElement(v, 2);

    for (auto it : v)
    {
        cout << it << " ";
    }

    return 0;
}