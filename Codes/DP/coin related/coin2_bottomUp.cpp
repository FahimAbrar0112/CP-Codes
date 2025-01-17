#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    dp.resize(n + 1, vector<int>(amount + 5, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = 0ll + dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
        }
    }

    return dp[n][amount];
}

int main(void)
{

    vector<int> coins = {1, 2, 5};
    cout << change(5, coins) << endl;
}