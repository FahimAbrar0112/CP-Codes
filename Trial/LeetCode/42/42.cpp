#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int>leftMaxHeight(n),rightMaxHeight(n);

        int l_Max=0;
        for(int i=0;i<n;i++)
        {
            leftMaxHeight[i]=l_Max;
            if(height[i]>l_Max)
             l_Max=height[i];
        }

        int r_max=0;
        for(int i=n-1;i>=0;i--)
        {
            rightMaxHeight[i]=r_max;
            if(height[i]>r_max)
             r_max=height[i];
        }

        int totalWater=0;

        for(int i=0;i<n;i++)
        {
            int canHold = min(leftMaxHeight[i],rightMaxHeight[i]);
            canHold -= height[i];
            if(canHold>0)
             totalWater+=canHold;
        }
        return totalWater;
    }
};

int main(void)
{   
    

    vector<int> height1 ={0,1,0,2,1,0,1,3,2,1,2,1};

    vector<int>height2 = {4,2,0,3,2,5};

    Solution S;
    cout<<S.trap(height1)<<endl;
    cout<<S.trap(height2)<<endl;

}