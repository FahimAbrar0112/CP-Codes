#include <bits/stdc++.h>
using namespace std;

// O( N  )
class Solution
{
public:
    /**
     * Inserts a new interval into a sorted list of non-overlapping intervals and merges if necessary.
     *
     * @param intervals A vector of intervals sorted by start time.
     * @param newInterval A single interval to be inserted and merged if required.
     * @return A vector of merged intervals.
     */
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> merged;
        int i = 0, n = intervals.size();

        // Add all intervals that come before the new interval without overlap
        while (i < n && intervals[i][1] < newInterval[0])
        {
            merged.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        // Add the merged new interval
        merged.push_back(newInterval);

        // Add all remaining intervals after merging
        while (i < n)
        {
            merged.push_back(intervals[i]);
            i++;
        }

        return merged;
    }
};

// O( n log n)
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        vector<vector<int>> merged;

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        merged.push_back(intervals[0]);
        int n = intervals.size();

        for (int i = 1; i < n; i++)
        {

            if (intervals[i][0] <= merged.back()[1])
            {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
            else
            {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};
