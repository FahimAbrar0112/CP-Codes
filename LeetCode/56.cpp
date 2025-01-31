#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> merged;
        if (intervals.size() == 0)
            return merged;

        // Sort intervals based on the start times; if equal, then by end times
        sort(intervals.begin(), intervals.end());

        // Add the first interval to the merged list
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            int ind = merged.size() - 1;

            // If the current interval overlaps with the last merged interval, merge them
            if (intervals[i][0] <= merged[ind][1])
            {
                merged[ind][1] = max(merged[ind][1], intervals[i][1]);
            }
            else
            {
                // Otherwise, add the current interval to the merged list
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};
