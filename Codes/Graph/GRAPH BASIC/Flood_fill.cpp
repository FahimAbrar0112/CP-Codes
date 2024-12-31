// https : // leetcode.com/problems/flood-fill/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<pair<int, int>> movements = {
        {-1, 0}, {0, 1}, {0, -1}, {1, 0}};

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();
        int initialColor = image[sr][sc];

        if (initialColor != color)
            dfs(image, sr, sc, color, n, m, initialColor);

        return image;
    }

    bool isValied(int x, int y, int n, int m)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int n, int m, int initialColor)
    {
        image[sr][sc] = color;

        for (auto move : movements)
        {
            int x = sr + move.first;
            int y = sc + move.second;

            if (isValied(x, y, n, m) && image[x][y] == initialColor)
            {
                dfs(image, x, y, color, n, m, initialColor);
            }
        }
    }
};

int main(void)
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        grid.push_back(tmp);
    }

    for (auto img : grid)
    {
        for (auto val : img)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    Solution s;
    auto image = s.floodFill(grid, 1, 1, 2);

    cout << endl;
    for (auto img : image)
    {
        for (auto val : img)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

/*
    3 3
    1 1 1
    1 1 0
    1 0 1

*/