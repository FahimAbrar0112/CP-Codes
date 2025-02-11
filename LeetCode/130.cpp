#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int m, n;
    vector<pair<int, int>> movements= {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool isValid(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void dfs(int i, int j, vector<vector<char>> &board)
    {
        if (!isValid(i, j))
            return;
        if (board[i][j] !='O')
            return;

        board[i][j] = '#';

        for (auto move : movements)
        {

            int newX = move.first + i;
            int newY = move.second + j;

            dfs(newX, newY, board);
        }
    }

    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++)
        {

            if (board[i][0] == 'O')
                dfs(i, 0, board);
            if (board[i][n - 1] == 'O')
                dfs(i, n - 1, board);
        }

        for (int j = 0; j < n; j++)
        {

            if (board[0][j] == 'O')
                dfs(0, j, board);
            if (board[m - 1][j] == 'O')
                dfs(m - 1, j, board);
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X'; 
                else if (board[i][j] == '#')
                    board[i][j] = 'O';  
            }
        }

    }
};

// Function to print the board
void printBoard(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
            cout << cell << " ";
        cout << endl;
    }
}
int main()
{
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'O', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'X'}};

    cout << "Input Board:\n";
    printBoard(board);

    Solution sol;
    sol.solve(board);

    cout << "\nOutput Board:\n";
    printBoard(board);

    return 0;
}


