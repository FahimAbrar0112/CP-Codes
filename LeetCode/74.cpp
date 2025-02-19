#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int lo = 0, hi = m * n - 1;

        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            int midValue = matrix[mid / n][mid % n];
            if (target < midValue)
            {
                hi = mid -1;
            }
            else
            {
                lo = mid;
            }
        }

        if (matrix[lo / n][lo % n] ==target || matrix[hi / n][hi % n] == target)
            return 1;

        return 0;
    }
};
