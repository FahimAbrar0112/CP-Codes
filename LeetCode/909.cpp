#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> getCoordinates(int pos, int N)
    {
        int row = N - 1 - (pos - 1) / N; // Compute row index
        int col = (pos - 1) % N;         // Compute col index

        // Reverse column for odd rows (zig-zag pattern)

        int quotient = (pos - 1) / N;

        // row  0,2,4 => right to left
        // row  1,3,5 => left to right
        // quetiont even hoile odd row mane row 1,3,5 left to right column so column (pos-1)%N ;
        // But, quetiont odd hoile even row mane row 0,2,4 right to left column So, column  = N-1 - (pos-1)%N;

        if (quotient % 2 == 1)
            col = N - 1 - col;

        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        int steps = 0;

        queue<int> q;
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(n, 0));

        q.push(1);
        visited[n - 1][0] = 1;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                int x = q.front();
                q.pop();

                if (x == n * n)
                    return steps;

                for (int k = 1; k <= 6; k++)
                {
                    int newPosition = x + k;

                    if (newPosition > n * n)
                        break;

                    pair<int, int> cordinate = getCoordinates(newPosition, n);

                    if (visited[cordinate.first][cordinate.second])
                        continue;

                    visited[cordinate.first][cordinate.second] = 1;

                    if (board[cordinate.first][cordinate.second] == -1)
                    {
                        q.push(newPosition);
                    }
                    else
                    {
                        q.push(board[cordinate.first][cordinate.second]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
