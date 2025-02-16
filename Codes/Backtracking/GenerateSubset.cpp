#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> valied;
void generate(vector<int> &subset, int index, vector<int> &nums)
{
    if (index == nums.size())
    {
        valied.push_back(subset);
        return;
    }

    // ith elem include:
    subset.push_back(nums[index]);
    generate(subset, index + 1, nums);
    subset.pop_back();

    // ith not including:
    generate(subset, index + 1, nums);
}


void show()
{   
    for(auto vals:valied)
    {
        for(auto val:vals)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
}

int main(void)
{

    vector<int> nums = {1, 2, 3};
    vector<int> subset;
    generate(subset, 0, nums);
    show();
}