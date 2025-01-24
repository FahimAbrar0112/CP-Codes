#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans; // To store the elements in spiral order

        int m = matrix.size();    // Number of rows in the matrix
        int n = matrix[0].size(); // Number of columns in the matrix

        // Define boundaries for traversal
        int left = 0, right = n, top = 0, bottom = m;

        // Continue looping while there are elements to traverse
        while (left < right && top < bottom)
        {
            // Traverse from left to right along the top row
            for (int i = left; i < right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++; // Move the top boundary down

            // Traverse from top to bottom along the rightmost column
            for (int j = top; j < bottom; j++)
            {
                ans.push_back(matrix[j][right - 1]);
            }
            right--; // Move the right boundary left

            // Check for row or column exhaustion to avoid redundant processing
            if (left >= right || top >= bottom)
                break;

            // Traverse from right to left along the bottom row
            for (int i = right - 1; i >= left; i--)
            {
                ans.push_back(matrix[bottom - 1][i]);
            }
            bottom--; // Move the bottom boundary up

            // Traverse from bottom to top along the leftmost column
            for (int j = bottom - 1; j >= top; j--)
            {
                ans.push_back(matrix[j][left]);
            }
            left++; // Move the left boundary right
        }
        return ans; // Return the final spiral order result
    }
};
