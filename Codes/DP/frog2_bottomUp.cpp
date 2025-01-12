#include <bits/stdc++.h>
using namespace std;
vector<int> heights;
vector<long long> dp;

int main(void)
{
    int n, k;
    cin >> n >> k;

    dp.resize(n + 1, INT_MAX);
    heights.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> heights[i];
    }

    dp[1] = 0;
    dp[2] = abs(heights[2] - heights[1]);

    for (int i = 3; i <= n; i++)
    {
        long long cost = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                cost = min(cost, dp[i - j] + abs(heights[i - j] - heights[i]));
        }

        dp[i] = cost;
    }

    cout << dp[n] << endl;
}