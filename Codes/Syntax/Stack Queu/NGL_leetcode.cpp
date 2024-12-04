#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums2.size(); i++)
        {
            if (st.empty())
            {
                st.push(i);
                // cout << nums2[i] << endl;
            }
            else
            {
                while (nums2[i] > nums2[st.top()])
                {

                    mp[nums2[st.top()]] = nums2[i];
                    // cout << "GG  " << nums2[st.top()] << " " << nums2[i] << endl;
                    st.pop();
                    if (st.empty())
                        break;
                }
                st.push(i);
            }
        }

        while (!st.empty())
        {
            mp[nums2[st.top()]] = -1;
            st.pop();
            // cout << "y1";
        }

        vector<int> v;
        for (auto val : nums1)
        {
            v.push_back(mp[val]);
            // cout << "R";
        }

        return v;
    }
};

int main(void)
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    Solution s;
    cout << "FF";

    vector<int> v = s.nextGreaterElement(nums1, nums2);
    for (auto val : v)
    {
        cout << val << " ";
    }
}