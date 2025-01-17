#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));

        // Base case: Amount 0 requires 0 coins
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) // i=> coin  j=> amount
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] > j)
                { // simply copying from above row
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    // not including ith coin
                    dp[i][j] = dp[i - 1][j];

                    // including ith coin
                    if (dp[i][j - coins[i - 1]] != INT_MAX)
                        dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
                }
            }
        }

        // Final result
        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};

int main(void)
{

    vector<int> coins = {3, 5};
    int amount = 22; // 3 3 3 3 5 5
    Solution s;

    cout << s.coinChange(coins, amount) << endl;
}