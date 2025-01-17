#include <bits/stdc++.h>
using namespace std;
vector<int> coins;
vector<int> numberOfCoins;
vector<vector<int>> dp;

int func(int ind, int amount)
{
    if (amount == 0)
        return 1;
    if (ind < 0)
        return 0;
    if (dp[ind][amount] != -1)
        return dp[ind][amount];

    int coin = coins[ind];
    int ways = 0;

    for (int coin_amount = 0; coin_amount <= coin * numberOfCoins[ind]; coin_amount += coin)
    {
        if (amount - coin_amount >= 0)
            ways += func(ind - 1, amount - coin_amount);
    }

    return dp[ind][amount] = ways;
}

int main(void)
{
    int n, amount;

    cin >> n >> amount;
    dp.resize(n + 1, vector<int>(amount + 5, -1));

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        coins.push_back(x);
        numberOfCoins.push_back(y);
    }

    cout << func(n - 1, amount) << endl;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }
}

/*

    3 5
    1 2
    2 1
    5 1

    // 1

    3 5
    1 2
    2 1
    5 1

    // 1

    4 6
    1 3
    2 2
    3 2
    4 1

    // 6
    NOTE:
            4+2
            4+1+1
            3+3
            3+1+1+1
            3+2+1
            2+2+1+1

 */

/*
        ### Problem Statement: **Finite Coin Combinations**

You are given  n types of coins, where each coin has a value  coins[i]   and a limited quantity   numberOfCoins[i] . Your task is to determine the number of distinct ways to make an amount   using these coins.
Each type of coin can be used at most   numberOfCoins[i]  times.

     4 6
    1 3
    2 2
    3 2
    4 1

     n = 4
    amount = 6
    coins =   1 2 3 4
    # coins=  3 2 2 1
*/