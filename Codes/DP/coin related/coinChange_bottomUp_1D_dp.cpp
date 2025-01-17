#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp;

    int coinChange(vector<int> &coins, int amount)
    {
        dp.resize(amount + 10, INT_MAX);

        dp[0] = 0;

        for (int coin : coins)
        {
            for (int x = coin; x <= amount; x++)
            {
                if (dp[x - coin] != INT_MAX)
                {
                    dp[x] = min(dp[x], dp[x - coin] + 1);
                }
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};

int main(void)
{

    vector<int> coins = {3, 5};
    int amount = 22; // 3 3 3 3 5 5
    Solution s;

    cout << s.coinChange(coins, amount) << endl;
}