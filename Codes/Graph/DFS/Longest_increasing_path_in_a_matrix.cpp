// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    int n, m;

    vector<pair<int, int>> movements = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

public:
    bool isValied(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

    int dfs(vector<vector<int>> &matrix, int x, int y, vector<vector<int>> &dp)
    {
        if (dp[x][y] != -1)
            return dp[x][y];

        int maxPath = 1;
        for (auto move : movements)
        {
            int new_x = x + move.first;
            int new_y = y + move.second;
            if (isValied(new_x, new_y) &&
                (matrix[new_x][new_y] > matrix[x][y]))
            {

                maxPath = max(maxPath, 1 + dfs(matrix, new_x, new_y, dp));
            }
        }

        dp[x][y] = maxPath;
        return dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {

        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int finalAns = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                finalAns = max(finalAns, dfs(matrix, i, j, dp));
            }
        }
        return finalAns;
    }
};

int main(void)
{
    int n, m;
    cin >> n >> m;
    Solution s;
    vector<vector<int>> v;

    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        v.push_back(tmp);
    }

    cout << s.longestIncreasingPath(v) << endl;

    // int ct = 1;
    // dfs(v, ct, 0, 0);
}

/*

    1 2
    1 2

    3 3

    9 8 10
    7 4 8
    5 2 1



    3 3

    3 4 5
    3 2 6
    2 2 1


    3 3
    9 9 4
    6 6 8
    2 1 1


*/