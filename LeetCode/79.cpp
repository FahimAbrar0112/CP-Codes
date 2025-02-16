#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<bool>> visited;
    vector<pair<int, int>> movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool isValid(int i, int j, vector<vector<char>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();
        return i >= 0 && j >= 0 && i < rows && j < cols;
    }

    bool generate(vector<vector<char>> &board, string &word, int i, int j, int index)
    {
        if (index == word.size())
            return 1;

        if (!isValid(i, j, board) || visited[i][j] || board[i][j] != word[index])
            return 0;

        visited[i][j] = 1;

        for (auto move : movements)
        {
            int x = i + move.first;
            int y = j + move.second;

            if (generate(board, word, x, y, index + 1))
                return 1;
        }

        visited[i][j] = 0;
        return 0;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (generate(board, word, i, j, 0))
                        return 1;
                }
            }
        }
        return 0;
    }
};
