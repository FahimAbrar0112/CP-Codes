#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {

        int ct = 1;
        int n = points.size();

        if (n == 0)
            return 0;
        // Sorted based on end points.
        sort(points.begin(), points.end(),
             [](vector<int> &a, vector<int> &b)
             {
                 return a[1] < b[1];
             }

        );

        /*
                points[0] er end point ta hosse shobar end point theke soto.
                i=1 theke jader starting point points[0] er end point theke soto tader shobar end point points[0] er end point theke boro. mane oi shob gular moddhe common point hosse points[0] er end point. so oder shobar jonno akta arrow e enough.

                simulate the example:
                [[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]

                here, 6-7 er 7  our poinnts[0] er end point
        */

        int endPoint = points[0][1];
        for (int i = 1; i < n; i++)
        {
            if (points[i][0] > endPoint)
            {
                ct++;
                endPoint = points[i][1];
            }
        }
        return ct;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << sol.findMinArrowShots(points1) << endl; // Output: 2

    vector<vector<int>> points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << sol.findMinArrowShots(points2) << endl; // Output: 4

    vector<vector<int>> points3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << sol.findMinArrowShots(points3) << endl; // Output: 2

    return 0;
}
