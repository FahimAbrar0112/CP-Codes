#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxArea=0;
        int left=0,right=height.size()-1;

        while(left<right)
        {
            int tmpArea = (right-left)*min(height[left],height[right]);

            maxArea = max(maxArea,tmpArea);

            if(height[left]<height[right])
            left++;
            else
            right--;

        }
        
        return maxArea;
    }
};




int main(void)
{   
    vector<int> v = {4,3, 10,8,7};

    Solution s;
    cout<<s.maxArea(v)<<endl;



}