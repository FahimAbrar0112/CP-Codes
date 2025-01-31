#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int m, n;

    vector<pair<int, int>> movements = {
        {-1, 0}, {-1, 1}, {-1, -1}, {0, 1}, {0, -1}, {1, 0}, {1, 1}, {1, -1}};

public:
    bool isValied(int i, int j)
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int aliveNeighbour(int i, int j, vector<vector<int>> &board)
    {
        int alive = 0;
        for (auto move : movements)
        {
            int x = i + move.first;
            int y = j + move.second;
            if (isValied(x, y))
            {
                alive += board[x][y];
            }
        }
        return alive;
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> copyBoard = board;
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int alive = aliveNeighbour(i, j, copyBoard);
                if (copyBoard[i][j] && alive < 2)
                {
                    board[i][j] = 0;
                }

                else if (copyBoard[i][j] && (alive == 2 || alive == 3))
                {
                    board[i][j] = 1;
                }
                else if (copyBoard[i][j] && alive > 3)
                {
                    board[i][j] = 0;
                }
                else if (copyBoard[i][j] == 0 && alive == 3)
                {
                    board[i][j] = 1;
                }
            }
        }
    }
};
