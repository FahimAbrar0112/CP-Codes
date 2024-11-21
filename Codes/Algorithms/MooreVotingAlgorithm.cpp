#include <bits/stdc++.h>
using namespace std;


int majorityElement(vector<int> &nums)
{
    int index = 0;
    int candidate = 0;
    // Finding cnadidate:
    for (auto val : nums)
    {
        if (index == 0)
        {
            candidate = val;
            // index++;
        }

        if (candidate == val)
            index++;
        else
            index--;
    }

    // Check candidate apeears > n/2 or not.
    int ct = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == candidate)
            ct++;
    }
    if (ct > nums.size() / 2)
        cout << "Majority Ele: " << candidate << endl;
    else
        cout << "No Majority Ele present." << endl;

    return candidate;
}

int main(void)
{
    vector<int>  v ={3,1,3,3,5,3};
    majorityElement(v);
    return 0;
}