#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        unordered_set<string> seen;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char ch = board[i][j];
                if (ch == '.')
                    continue;

                string rowKey = "row" + to_string(i) + ch;
                string colKey = "col" + to_string(j) + ch;
                string boxKey = "box" + to_string(i / 3) + to_string(j / 3) + ch;

                if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey))
                    return 0;

                seen.insert(rowKey);
                seen.insert(colKey);
                seen.insert(boxKey);
            }
        }
        return 1;
    }
};

int main(void)
{
}