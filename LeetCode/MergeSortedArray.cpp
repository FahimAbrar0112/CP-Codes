#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int l_array = m;
        int r_array = n;
        int arrL[l_array + 1];
        int arrR[n + 1];
        arrL[l_array] = INT_MAX;
        arrR[n] = INT_MAX;

        for (int i = 0; i < l_array; i++)
        {
            arrL[i] = nums1[i];
        }

        for (int i = 0; i < r_array; i++)
        {
            arrR[i] = nums2[i];
        }

        int l_i = 0, r_i = 0;
        for (int k = 0; k < m+n; k++)
        {
            if (arrL[l_i] <= arrR[r_i])
            {
                nums1[k] = arrL[l_i];
                l_i++;
            }
            else
            {
                nums1[k] = arrR[r_i];
                r_i++;
            }
        }
    }
};

int main()
{

    vector<int> nums1 = {1, 2, 3, 4, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    int m = 4, n = 3;

    Solution s;
    s.merge(nums1, m, nums2, n);

    for (int i = 0; i < m+n; i++)
    {
        cout << nums1[i] << "  ";
    }
}
